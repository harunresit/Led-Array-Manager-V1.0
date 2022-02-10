#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWheelEvent>
#include <QPoint>
#include <QListWidgetItem>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setParameters(QListWidgetItem ctrTypeName, int lghtNumber, QString sketch_input, QString byte_input);
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

    void mousePressEvent(QMouseEvent *event);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionYellow_Theme_triggered();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;

    //Controller type that will be selected from QListWidget will be stored here
    QListWidgetItem main_controllertypeitem;

    //Max led number will be stored here
    int main_lightnumber = 0;

    //Sketch file save path info will be stored here
    QString main_sketchpathinput = "";

    //Byte file save path info will be stored here
    QString main_bytepathinput = "";

    //All led info will be stored here
    QVector<int> ledlist;

    //Cursor status is Cursor type during draw
    CursorStatus cursorStatus = CURSOR;                                     //default

    //Sketch grid
    int sketchGridSize = 10;                                                //default

    //Sketch style (this may be removed)
    int sketchStyle = 1;                                                    //default

    //QGraphicsScene object for QgraphicsView (this is our sketch screen)
    QGraphicsScene *scene = new QGraphicsScene(this);

};
#endif // MAINWINDOW_H
