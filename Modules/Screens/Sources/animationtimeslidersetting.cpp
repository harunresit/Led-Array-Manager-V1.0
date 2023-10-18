#include "Modules/Screens/Headers/animationtimeslidersetting.h"
#include "ui_animationtimeslidersetting.h"
#include <QIntValidator>
#include <QScreen>
#include <QDebug>
#include <QGraphicsScene>
#include <QDesktopWidget>
#include <QProcess>
#include <QDataStream>

AnimationTimeSliderSetting::AnimationTimeSliderSetting(int ld, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimationTimeSliderSetting)
{
    led_count_x = ld;
    led_count_y = ld;

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

void AnimationTimeSliderSetting::on_pushButton_3_clicked()
{

    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    //Button screen caster
    qDebug() << "Screen casting" << endl;
    qDebug() << "Please click the point that you want to record" << endl;

    qDebug() << system("sh cathchMouseClick.sh") << endl;



    QFile txtFile("positions.txt");
    QStringList list;

    if (txtFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream in(&txtFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line[0] == "X") {
                if (line[1] == "1") {
                    //x1
                    list = line.split('=');
                    x1 = list[1].toInt();
                    qDebug() << list << endl;
                } else if (line[1] == "3") {
                    //x2
                    list = line.split('=');
                    x2 = list[1].toInt();
                    qDebug() << list << endl;
                }

            } else if (line[0] == "Y") {
                if (line[1] == "1") {
                    //y1
                    list = line.split('=');
                    y1 = list[1].toInt();
                    qDebug() << list << endl;
                } else if (line[1] == "3") {
                    //y2
                    list = line.split('=');
                    y2 = list[1].toInt();
                    qDebug() << list << endl;
                }

            }

        }
        txtFile.close();
    }

    qDebug() << "X1: " << x1 << endl;
    qDebug() << "Y1: " << y1 << endl;
    qDebug() << "X2: " << x2 << endl;
    qDebug() << "Y2: " << y2 << endl;


    //Clear the file content
    txtFile.open(QFile::WriteOnly | QFile::Truncate);
    txtFile.close();


    QLabel* lbl = new QLabel(this);
    lbl->setAlignment(Qt::AlignCenter);

    QScreen* screen = QGuiApplication::primaryScreen();
    QPixmap screenGrab = screen->grabWindow(QApplication::desktop()->winId(), x1, y1, x2-x1, y2-y1);
    QImage grabbedImage = screenGrab.toImage();
    qDebug() << " Image pixel:  " << QColor(grabbedImage.pixel(5,5)) << endl;
    qDebug() << " Image size:   " << grabbedImage.size() << endl;
    qDebug() << " X Edge: " << led_count_x << endl;
    qDebug() << " Y Edge: " << led_count_y << endl;
    lbl->setPixmap(screenGrab);
    lbl->show();

}

