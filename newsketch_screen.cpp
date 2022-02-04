#include "newsketch_screen.h"
#include "ui_newsketch_screen.h"
#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>

newsketch_screen::newsketch_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newsketch_screen)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    ui->lightNumberlineEdit->setValidator(new QIntValidator(0, 2048, ui->lightNumberlineEdit));
}

newsketch_screen::~newsketch_screen()
{
    delete ui;
}

void newsketch_screen::on_buttonBox_accepted()
{
    bool passable = 1;
    QString warningmessage = "";
    if (lightnumber == 0 || lightnumber > 2048) {
        qDebug() << "Please input a valid light number!" << endl;
        warningmessage = warningmessage + "Please input a valid light number!\n";
        passable = 0;
    }
    if (controllertypeitem.text() == "") {
        qDebug() << "Please select a controller!" << endl;
        warningmessage = warningmessage + "Please select a controller!";
        passable = 0;
    }
    if (passable == 1) {
        MainWindow *w = new MainWindow();
        w->setAttribute(Qt::WA_DeleteOnClose);
        w->setParameters(controllertypeitem, lightnumber);
        w->show();
    }else {
        QMessageBox msgbox;
        msgbox.setIcon(QMessageBox::Icon::Warning);
        msgbox.setText(warningmessage);
        msgbox.exec();
    }
}


void newsketch_screen::on_controllerTypeList_itemClicked(QListWidgetItem *item)
{
    controllertypeitem = *item;
    ui->currentControllerLabel->setText("Current Controller: " + controllertypeitem.text());
}



void newsketch_screen::on_lightNumberlineEdit_textEdited(const QString &arg1)
{
    lightnumber = arg1.toInt();
}


