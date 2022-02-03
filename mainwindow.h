#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWheelEvent>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int sketchGridSize = 10;                            //default
    int sketchStyle = 1;                                //default

    enum CursorStatus{
        LED,
        CURSOR,
        ERASER
    };

private slots:
    void on_pushButton_clicked();

    void on_actionDark_Theme_triggered();

    void on_actionWhite_Theme_triggered();

    void on_actionGreen_Theme_triggered();

    void on_actionBlue_Theme_triggered();

    void wheelEvent(QWheelEvent *event);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionYellow_Theme_triggered();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;

    CursorStatus cursorStatus = CURSOR;                                     //default
    static QPixmap drawPattern(int type, int step, const QColor &color);
    static void drawSquare(QPainter *painter, int width, const QColor &color);
    static void drawCross(QPainter *painter, int width, const QColor &color);
    static void drawFancy(QPainter *painter, int width, const QColor &color);
};
#endif // MAINWINDOW_H
