#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionDark_Theme_triggered();

    void on_actionWhite_Theme_triggered();

    void on_actionRed_Theme_triggered();

    void on_actionGreen_Theme_triggered();

    void on_actionBlue_Theme_triggered();

private:
    Ui::MainWindow *ui;

    static QPixmap drawPattern(int type, int step, const QColor &color);
    static void drawSquare(QPainter *painter, int width, const QColor &color);
    static void drawCross(QPainter *painter, int width, const QColor &color);
    static void drawFancy(QPainter *painter, int width, const QColor &color);
};
#endif // MAINWINDOW_H
