#ifndef ANIMATIONTIMESLIDERSETTING_H
#define ANIMATIONTIMESLIDERSETTING_H

#include <QDialog>

namespace Ui {
class AnimationTimeSliderSetting;
}

class AnimationTimeSliderSetting : public QDialog
{
    Q_OBJECT

public:
    explicit AnimationTimeSliderSetting(QWidget *parent = nullptr);
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

private:
    Ui::AnimationTimeSliderSetting *ui;

    int sliderMax = 0;

    int sliderPosition = 0;

    int sliderInterval = 0;
};

#endif // ANIMATIONTIMESLIDERSETTING_H
