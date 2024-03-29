﻿#include "Modules/Screens/Headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "Modules/Screens/Headers/newsketch_screen.h"
#include "Modules/Processes/Graphical/Headers/draw.h"
#include "Modules/Processes/Graphical/Headers/view.h"
#include "Modules/Screens/Headers/animationrgb.h"

#include <QDebug>
#include <QFileDialog>
#include <qmath.h>
#include <QLabel>
#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //ui->sketchgraphicsView->setScene(scene);
    //ui->sketchgraphicsView->setBackgroundBrush(QBrush(Draw().drawPattern(sketchStyle, sketchGridSize, QColor(216,15,15))));

}

MainWindow::~MainWindow()
{
    qDebug() << "Are you sure you wanna quit?" << endl;
    delete ui;
}

void MainWindow::setParameters(QListWidgetItem ctrTypeName, int lghtNumber, QString sketch_input, QString byte_input){
    main_controllertypeitem = ctrTypeName;
    main_lightnumber = lghtNumber;
    main_sketchpathinput = sketch_input;
    main_bytepathinput = byte_input;

    populateScene(main_lightnumber);

    view = new View("Drawing sketch");

    view->view()->setScene(scene);

    ui->gridLayout->addWidget(view);

    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    connect(view, SIGNAL(sendAnimSignal()), this, SLOT(animationMake()));
    connect(view, SIGNAL(triggerTimeLineMenu()), this, SLOT(createTimeLineMenu()));
    connect(view, SIGNAL(stopAnimSignal()), this, SLOT(animationStop()));
    ///// DENEME
    //scene->addLine(40,20,110,20, QPen(Qt::red, 3));
    /////
}

void MainWindow::clickedLed(Led *led)
{
    if (view->modeAnim() == false) {
        ///Led point mode
        led->setNumber(ledCount);
        qDebug() << led->returnNum() << endl;
        if (clickedLedList.empty()) {
            qDebug() << "This shit was just empty" << endl;
            clickedLedList.append(led);
            led->setOpacity(1);
            ledCount += 1;
        } else {
            ///Faint to Shiny
            if (led->opacity() == 0.1) {

                led->setOpacity(1);
                ledCount += 1;

                ///Drawing line process
                QGraphicsLineItem *line = scene->addLine(clickedLedList.at(ledCount-2)->pos().x()+20, clickedLedList.at(ledCount-2)->pos().y()+20, led->pos().x()+20, led->pos().y()+20, QPen(Qt::red, 3));

                lines.append(line);

                clickedLedList.append(led);
            } else {
                ///Shint to Faint
                led->setOpacity(0.1);
                scene->removeItem(lines.at(ledCount-2));
                lines.remove(ledCount-2);
                clickedLedList.remove(ledCount-1);
                ledCount--;
            }
        }
    } else {
        ///Animation mode
        if (std::find(clickedLedList.begin(), clickedLedList.end(), led) != clickedLedList.end()) {
            qDebug() << "ANIMATION MODE ON" << endl;
            clickedLedforAnim = led;
            AnimationRGB *rgbScreen = new AnimationRGB();
            connect(rgbScreen, SIGNAL(dialogAccepted(int,int,int)), this, SLOT(rgbAnimOk(int,int,int)));
            currentLedSequence = timeSliderMenu->getSliderPos();
            qDebug() << "Active sequence" << currentLedSequence << endl;
            timeLimit = timeSliderMenu->getSliderMax();
            timeInterval = timeSliderMenu->getSliderInterval();
            rgbScreen->show();
        } else {
            qDebug() << "Led not clicked" << endl;
        }
    }

    qDebug() << "CLICKED LED" << endl;
}

void MainWindow::rgbAnimOk(int r, int g, int b)
{
    LedAnim *animled = new LedAnim;
    animled->led = clickedLedforAnim;
    animled->redvalue = r;
    animled->greenvalue = g;
    animled->bluevalue = b;
    animled->activeSequence = currentLedSequence;
    animLedList.append(animled);
}

void MainWindow::animationMake()
{
    qDebug() << "Animation making started" << endl;
    currentLedSequence = 0;

    animationTime = new QTimer;
    connect(animationTime, SIGNAL(timeout()), this, SLOT(makeAnimationLedOn()));
    animationTime->start(timeInterval);

    qDebug() << "Anim Led list : " << endl;
    for (LedAnim *a : animLedList) {
        qDebug() << a->activeSequence << endl;
    }


/*
    for (int i=0; i<animLedList.size(); i++) {

        ///LED ON
        QSignalMapper* mapperOn = new QSignalMapper(this);
        connect(mapperOn, SIGNAL(mapped(int)), this, SLOT(makeAnimationLedOn(int)));
        mapperOn->setMapping(animLedList[i]->timeron, i);

        connect(animLedList[i]->timeron, SIGNAL(timeout()), mapperOn, SLOT(map()));
        connect(animLedList[i]->timeron, SIGNAL(timeout()), mapperOn, SLOT(map()));
        animLedList[i]->timeron->setInterval(animLedList[i]->ontimevalue);


        ///LED OFF
        QSignalMapper* mapperOff = new QSignalMapper(this);
        connect(mapperOff, SIGNAL(mapped(int)), this, SLOT(makeAnimationLedOff(int)));
        mapperOff->setMapping(animLedList[i]->timeroff, i);

        connect(animLedList[i]->timeroff, SIGNAL(timeout()), mapperOff, SLOT(map()));
        connect(animLedList[i]->timeroff, SIGNAL(timeout()), mapperOff, SLOT(map()));
        animLedList[i]->timeroff->setInterval(animLedList[i]->offtimevalue);

        ///START ANIMATION
        animLedList[i]->timeroff->start();
    }
    */
}

void MainWindow::makeAnimationLedOn()
{
    qDebug() << "Current led sequence under time limit " << currentLedSequence << endl;
    for (LedAnim *a : animLedList) {
        QColor color(250,250,250);
        a->led->setColor(color);
    }
    for (LedAnim *a : animLedList) {
        if (a->activeSequence == currentLedSequence) {
            QColor color(a->redvalue, a->greenvalue, a->bluevalue);
            a->led->setColor(color);
        }
    }

    if (currentLedSequence < timeLimit) {
        currentLedSequence++;

    } else {
        currentLedSequence = 0;
    }
    /*
    QColor color(250,250,250);
    animLedList[a]->led->setColor(color);
    animLedList[a]->timeron->stop();
    animLedList[a]->timeroff->start();*/
}

void MainWindow::createTimeLineMenu()
{
    timeSliderMenu = new AnimationTimeSliderSetting(led_counts);
    timeSliderMenu->show();
}

void MainWindow::animationStop()
{
    delete animationTime;
    for (LedAnim *a : animLedList) {
        QColor color(250,250,250);
        a->led->setColor(color);
    }
}

void MainWindow::populateScene(int lednumber) {
    scene = new QGraphicsScene(this);

    //QImage image(scene->width(), scene->height(), QImage::Format_ARGB32);
    led_counts = sqrt(lednumber);
    int x_edge = sqrt(lednumber);
    int y_edge = sqrt(lednumber);
    int imaginel_lednumber = x_edge * y_edge;
    qDebug() << x_edge << endl;
    qDebug() << y_edge << endl;
    qDebug() << imaginel_lednumber << endl;


    // Populate scene
    int xx = 0;
    int nitems = 0;
    x_edge *= 110;
    y_edge *= 70;
    for (int i = 0; i < x_edge; i += 110) {   //step: 110 //-1000,1000
        ++xx;
        int yy = 0;
        for (int j = 0; j < y_edge; j += 70) {    //step: 70 //-7000,7000
            ++yy;
            //qreal x = (i + 11000) / 22000.0;
            //qreal y = (j + 7000) / 14000.0;

            //QColor color(image.pixel(int(image.width() * x), int(image.height() * y)));
            QColor color(250,250,250);
            Led *item = new Led(color, xx, yy);
            //item->setVisible(false);
            item->setOpacity(0.1);
            item->setPos(QPointF(i, j));

            scene->addItem(item);

            connect(item, SIGNAL(viewPressed(Led*)), this, SLOT(clickedLed(Led*)));

            ++nitems;
        }
    }

}

