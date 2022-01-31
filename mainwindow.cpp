#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("background-color: red;");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
     qDebug() << "Date:" << QDate::currentDate();

}

void MainWindow::on_actionDark_Theme_triggered()
{
    ui->centralwidget->setStyleSheet("background-color: black;");
}


void MainWindow::on_actionWhite_Theme_triggered()
{
    ui->centralwidget->setStyleSheet("background-color: white;");
}


void MainWindow::on_actionRed_Theme_triggered()
{
    ui->centralwidget->setStyleSheet("background-color: red;");
}


void MainWindow::on_actionGreen_Theme_triggered()
{
    ui->centralwidget->setStyleSheet("background-color: green;");
}


void MainWindow::on_actionBlue_Theme_triggered()
{
    ui->centralwidget->setStyleSheet("background-color: blue;");
}

