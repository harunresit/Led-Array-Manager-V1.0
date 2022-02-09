#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newsketch_screen.h"
#include "draw.h"

#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("background-color: red;");
    ui->pushButton_2->setStyleSheet("background-color: green;");

    ui->sketchgraphicsView->setScene(scene);
    ui->sketchgraphicsView->setBackgroundBrush(QBrush(Draw().drawPattern(sketchStyle, sketchGridSize, QColor(216,15,15))));
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
}

void MainWindow::on_pushButton_clicked()
{
    sketchStyle = 1;
    ui->sketchgraphicsView->setBackgroundBrush(QBrush(Draw().drawPattern(sketchStyle, sketchGridSize, QColor(216,15,15))));
}

void MainWindow::on_actionDark_Theme_triggered()
{
    ui->sketchgraphicsView->setStyleSheet("background-color: black;");
}


void MainWindow::on_actionWhite_Theme_triggered()
{
    ui->sketchgraphicsView->setStyleSheet("background-color: white;");
}

void MainWindow::on_actionGreen_Theme_triggered()
{
    ui->sketchgraphicsView->setStyleSheet("background-color: #CEFF33;");
}


void MainWindow::on_actionBlue_Theme_triggered()
{
    ui->sketchgraphicsView->setStyleSheet("background-color: #33FFF6;");
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees = event->angleDelta() / 120;

    if (numDegrees.y() == 1){
        sketchGridSize++;
    }else if (numDegrees.y() == -1){
        sketchGridSize--;
    }

    if (sketchGridSize <= 10){
        sketchGridSize = 10;
    }else if (sketchGridSize >= 100){
        sketchGridSize = 100;
    }

    ui->sketchgraphicsView->setBackgroundBrush(QBrush(Draw().drawPattern(sketchStyle, sketchGridSize, QColor(216,15,15))));
    event->accept();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint remapped = ui->sketchgraphicsView->mapFromParent(event->pos());
    if (ui->sketchgraphicsView->rect().contains(remapped)) {
        QPointF mousePoint = ui->sketchgraphicsView->mapToScene(remapped);
        Draw::drawLed(scene, mousePoint);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    sketchStyle = 0;
    ui->sketchgraphicsView->setBackgroundBrush(QBrush(Draw().drawPattern(sketchStyle, sketchGridSize, QColor(216,15,15))));

}


void MainWindow::on_pushButton_3_clicked()
{
    sketchStyle = 2;
    ui->sketchgraphicsView->setBackgroundBrush(QBrush(Draw().drawPattern(sketchStyle, sketchGridSize, QColor(216,15,15))));
}


void MainWindow::on_actionYellow_Theme_triggered()
{
    ui->sketchgraphicsView->setStyleSheet("background-color: #E6FF33;");
}


void MainWindow::on_pushButton_5_clicked()
{
    qDebug() << main_bytepathinput << endl;
    qDebug() << main_sketchpathinput << endl;
    qDebug() << main_lightnumber << endl;
    qDebug() << main_controllertypeitem.text() << endl;
    cursorStatus = LED;
}


void MainWindow::on_pushButton_4_clicked()
{
    cursorStatus = CURSOR;
}


void MainWindow::on_pushButton_6_clicked()
{
    cursorStatus = ERASER;
}


void MainWindow::on_actionNew_triggered()
{
    newsketch_screen().setModal(true);
    newsketch_screen().exec();
}


void MainWindow::on_actionOpen_triggered()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),"/path/to/file/",tr("Mp3 Files (*.ld)"));
    //ld.open();
}

