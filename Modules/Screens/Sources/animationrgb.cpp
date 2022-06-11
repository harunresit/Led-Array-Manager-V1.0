#include "Modules/Screens/Headers/animationrgb.h"
#include "ui_animationrgb.h"
#include <QDebug>

AnimationRGB::AnimationRGB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimationRGB)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

    red = 0;
    green = 0;
    blue = 0;
    ontime = 0;
    offtime = 0;

    QPalette pal;
    pal = ui->pushButton->palette();
    pal.setColor(QPalette::Button, QColor(red, green, blue));
    ui->pushButton->setAutoFillBackground(true);
    ui->pushButton->setPalette(pal);
    ui->pushButton->update();
}

AnimationRGB::~AnimationRGB()
{
    delete ui;
}


void AnimationRGB::on_spinBox_valueChanged(int arg1)
{
    red = arg1;
    ui->verticalSlider->setSliderPosition(arg1);

    QPalette pal;
    pal.setColor(QPalette::Button, QColor(red, green, blue));
    ui->pushButton->setPalette(pal);
    ui->pushButton->update();
}

void AnimationRGB::on_verticalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
}

void AnimationRGB::on_spinBox_2_valueChanged(int arg1)
{
    green = arg1;
    ui->verticalSlider_2->setSliderPosition(arg1);

    QPalette pal;
    pal.setColor(QPalette::Button, QColor(red, green, blue));
    ui->pushButton->setPalette(pal);
    ui->pushButton->update();
}

void AnimationRGB::on_verticalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
}

void AnimationRGB::on_spinBox_3_valueChanged(int arg1)
{
    blue = arg1;
    ui->verticalSlider_3->setSliderPosition(arg1);

    QPalette pal;
    pal.setColor(QPalette::Button, QColor(red, green, blue));
    ui->pushButton->setPalette(pal);
    ui->pushButton->update();
}

void AnimationRGB::on_verticalSlider_3_valueChanged(int value)
{
    ui->spinBox_3->setValue(value);
}


void AnimationRGB::on_buttonBox_accepted()
{
    emit dialogAccepted(red, green, blue, ontime, offtime);
}

void AnimationRGB::on_lineEdit_textEdited(const QString &arg1)
{
    offtime = arg1.toInt();
}

void AnimationRGB::on_lineEdit_2_textEdited(const QString &arg1)
{
    ontime = arg1.toInt();
}
