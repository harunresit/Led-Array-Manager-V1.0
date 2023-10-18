#ifndef ANIMATIONTIMESLIDERSETTING_H
#define ANIMATIONTIMESLIDERSETTING_H

#include <QDialog>
#include <QMouseEvent>

namespace Ui {
class AnimationTimeSliderSetting;
}

class AnimationTimeSliderSetting : public QDialog
{
    Q_OBJECT

public:
    explicit AnimationTimeSliderSetting(int ld=0, QWidget *parent = nullptr);
    ~AnimationTimeSliderSetting();

    int getSliderMax();

    int getSliderPos();

    int getSliderInterval();

    void setSliderPos(int);


private slots:

    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_pushButton_3_clicked();

    //void mouseClicked(QMouseEvent *e);

protected:
    //void mousePressEvent(QMouseEvent *event) ;

signals:
    //void mSignalTriggered(QMouseEvent *e);

private:
    Ui::AnimationTimeSliderSetting *ui;

    int sliderMax = 0;

    int sliderPosition = 0;

    int sliderInterval = 0;

    int led_count_x;
    int led_count_y;
};

#endif // ANIMATIONTIMESLIDERSETTING_H
