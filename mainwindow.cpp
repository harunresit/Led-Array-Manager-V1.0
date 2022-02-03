#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("background-color: red;");
    ui->pushButton_2->setStyleSheet("background-color: green;");

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->sketchgraphicsView->setScene(scene);
    ui->sketchgraphicsView->setBackgroundBrush(QBrush(MainWindow::drawPattern(sketchStyle, sketchGridSize, QColor(216,15,15))));

}

MainWindow::~MainWindow()
{
    qDebug() << "Are you sure you wanna quit?" << endl;
    delete ui;
}

void MainWindow::drawSquare(QPainter *painter, int width, const QColor &color)
{
    painter->setPen(color);
    painter->drawLine(0, 0, width, 0);
    painter->drawLine(0, 0, 0, width);
}

void MainWindow::drawCross(QPainter *painter, int width, const QColor &color)
{
    painter->setPen(color);
    painter->drawLine(0, 0, 2, 0);
    painter->drawLine(0, 0, 0, 2);
    painter->drawLine(0, width - 1, 0, width);
    painter->drawLine(width - 1, 0, width, 0);
}

void MainWindow::drawFancy(QPainter *painter, int width, const QColor &color)
{
    int halfWidth = 0.5*width + 0.5;

    painter->setPen(color.lighter(106));
    painter->drawLine(0, halfWidth, width, halfWidth);
    painter->drawLine(halfWidth, 0, halfWidth, width);
    painter->setPen(color);
    painter->drawLine(0, 0, width, 0);
    painter->drawLine(0, 0, 0, width);
    painter->setPen(color.darker(118));
    painter->drawPoint(halfWidth, halfWidth);
    painter->setPen(color.darker(160));
    painter->drawPoint(0, 0);
}

QPixmap MainWindow::drawPattern(int type, int step, const QColor &color)
{
    QPixmap pixmap(step, step);
    QPainter painter;
    int pixmapWidth = pixmap.width() - 1;

    pixmap.fill(Qt::transparent);

    painter.begin(&pixmap);

    switch (type) {
    case 0:
        drawSquare(&painter, pixmapWidth, color);
        break;
    case 1:
        drawCross(&painter, pixmapWidth, color);
        break;
    case 2:
        drawFancy(&painter, pixmapWidth, color);
        break;
        }

    return pixmap;
}

void MainWindow::on_pushButton_clicked()
{
    sketchStyle = 1;
    ui->sketchgraphicsView->setBackgroundBrush(QBrush(MainWindow::drawPattern(sketchStyle, sketchGridSize, QColor(216,15,15))));
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

    ui->sketchgraphicsView->setBackgroundBrush(QBrush(MainWindow::drawPattern(sketchStyle, sketchGridSize, QColor(216,15,15))));
    event->accept();
}

void MainWindow::on_pushButton_2_clicked()
{
    sketchStyle = 0;
    ui->sketchgraphicsView->setBackgroundBrush(QBrush(MainWindow::drawPattern(sketchStyle, sketchGridSize, QColor(216,15,15))));
}


void MainWindow::on_pushButton_3_clicked()
{
    sketchStyle = 2;
    ui->sketchgraphicsView->setBackgroundBrush(QBrush(MainWindow::drawPattern(sketchStyle, sketchGridSize, QColor(216,15,15))));
}


void MainWindow::on_actionYellow_Theme_triggered()
{
    ui->sketchgraphicsView->setStyleSheet("background-color: #E6FF33;");
}

