#ifndef ANIMATIONRGB_H
#define ANIMATIONRGB_H

#include <QDialog>

namespace Ui {
class AnimationRGB;
}

class AnimationRGB : public QDialog
{
    Q_OBJECT

public:
    explicit AnimationRGB(QWidget *parent = nullptr);
    ~AnimationRGB();

signals:
    void dialogAccepted(int, int, int, int, int);

private slots:

    void on_spinBox_valueChanged(int arg1);

    void on_verticalSlider_valueChanged(int value);

    void on_spinBox_2_valueChanged(int arg1);

    void on_verticalSlider_2_valueChanged(int value);

    void on_spinBox_3_valueChanged(int arg1);

    void on_verticalSlider_3_valueChanged(int value);

    void on_buttonBox_accepted();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

private:
    Ui::AnimationRGB *ui;

    int red;
    int green;
    int blue;
    int ontime;
    int offtime;
};

#endif // ANIMATIONRGB_H
