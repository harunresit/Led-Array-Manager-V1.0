#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*OBJECTS THOSE WAS MADE COMMENT LINE*/
/*
QGraphicsScene *scene
QVector<int> ledlist
*/

#include <QMainWindow>
#include <QPoint>
#include <QListWidgetItem>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QSplitter>
#include <QObject>
#include <QGraphicsLineItem>
#include <QFrame>
#include <QTimer>
#include "Modules/Processes/Graphical/Headers/view.h"
#include "Modules/Processes/Graphical/Headers/led.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QGraphicsScene;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setParameters(QListWidgetItem ctrTypeName, int lghtNumber, QString sketch_input, QString byte_input);

    void setAnimParams(int rgb, int offtime, int ontime);

    QGraphicsScene *scene;

    enum CursorStatus{
        LED,
        CURSOR,
        ERASER
    };

    class LedAnim : public QObject {
    public:
        Led *led;
        int redvalue;
        int greenvalue;
        int bluevalue;
        int ontimevalue;
        int offtimevalue;
        QTimer *timeron;
        QTimer *timeroff;

    };

    View *view;

private:
    Ui::MainWindow *ui;

    void populateScene(int lednumber);

    QSplitter *h1Splitter;
    QSplitter *h2Splitter;

    //Controller type that will be selected from QListWidget will be stored here
    QListWidgetItem main_controllertypeitem;

    //Max led number will be stored here
    int main_lightnumber = 0;

    //Sketch file save path info will be stored here
    QString main_sketchpathinput = "";

    //Byte file save path info will be stored here
    QString main_bytepathinput = "";

    //All led info will be stored here
    //QVector<int> ledlist;

    //Cursor status is Cursor type during draw
    CursorStatus cursorStatus = CURSOR;                                     //default

    //Sketch grid
    int sketchGridSize = 10;                                                //default

    //Sketch style (this may be removed)
    int sketchStyle = 1;                                                    //default

    //QGraphicsScene object for QgraphicsView (this is our sketch screen)
    //QGraphicsScene *scene = new QGraphicsScene(this);

    QVector<QGraphicsLineItem*> lines;
    QVector<Led*> clickedLedList;

    //Animation parameters
    Led *clickedLedforAnim;
    QVector<LedAnim*> animLedList;

    int ledCount = 0;


private slots:
    void clickedLed(Led*);

    void rgbAnimOk(int,int,int,int,int);

    void animationMake();

    void makeAnimationLedOn(int);

    void makeAnimationLedOff(int);


};
#endif // MAINWINDOW_H
