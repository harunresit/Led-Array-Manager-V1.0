#include "Modules/Screens/Headers/animationtimeslidersetting.h"
#include "ui_animationtimeslidersetting.h"
#include <QIntValidator>

AnimationTimeSliderSetting::AnimationTimeSliderSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimationTimeSliderSetting)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    ui->lineEdit->setValidator(new QIntValidator(ui->lineEdit));
    ui->lineEdit_2->setValidator(new QIntValidator(ui->lineEdit_2));
    sliderPosition = ui->horizontalSlider->sliderPosition();
}

AnimationTimeSliderSetting::~AnimationTimeSliderSetting()
{
    delete ui;
}

int AnimationTimeSliderSetting::getSliderMax()
{
    return sliderMax;
}

int AnimationTimeSliderSetting::getSliderPos()
{
    return sliderPosition;
}

int AnimationTimeSliderSetting::getSliderInterval()
{
    return sliderInterval;
}

void AnimationTimeSliderSetting::setSliderPos(int arg)
{
    ui->horizontalSlider->setSliderPosition(arg);
}

void AnimationTimeSliderSetting::on_lineEdit_textEdited(const QString &arg1)
{
    sliderMax = arg1.toInt();
    ui->horizontalSlider->setMaximum(sliderMax);
}

void AnimationTimeSliderSetting::on_pushButton_2_clicked()
{
    ///Plus button
    if (sliderPosition < sliderMax) {
        sliderPosition += 1;
        ui->horizontalSlider->setSliderPosition(sliderPosition);
    }
}

void AnimationTimeSliderSetting::on_pushButton_clicked()
{
    ///Minus button
    if (sliderPosition > 0) {
        sliderPosition -= 1;
        ui->horizontalSlider->setSliderPosition(sliderPosition);
    }
}

void AnimationTimeSliderSetting::on_lineEdit_2_textEdited(const QString &arg1)
{
    sliderInterval = arg1.toInt();
}
