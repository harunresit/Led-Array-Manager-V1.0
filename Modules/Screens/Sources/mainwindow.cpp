#include "Modules/Screens/Headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "Modules/Screens/Headers/newsketch_screen.h"
#include "Modules/Processes/Graphical/Headers/draw.h"
#include "Modules/Processes/Graphical/Headers/led.h"
#include "Modules/Processes/Graphical/Headers/view.h"

#include <QDebug>
#include <QFileDialog>
#include <qmath.h>

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

    View *view = new View("Drawing sketch");
    view->view()->setScene(scene);

    ui->gridLayout->addWidget(view);
}

void MainWindow::populateScene(int lednumber) {
    scene = new QGraphicsScene(this);

    //QImage image(scene->width(), scene->height(), QImage::Format_ARGB32);

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
            QColor color(250,250,150);
            QGraphicsItem *item = new Led(color, xx, yy);
            //item->setVisible(false);
            item->setOpacity(0.1);
            item->setPos(QPointF(i, j));
            scene->addItem(item);

            ++nitems;
        }
    }

}
