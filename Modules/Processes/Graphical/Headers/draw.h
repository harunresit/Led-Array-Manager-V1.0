#ifndef DRAW_H
#define DRAW_H
#include <QPixmap>
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>

class Draw
{
public:
    Draw();

    QPixmap drawPattern(int type, int step, const QColor &color);
    void drawSquare(QPainter *painter, int width, const QColor &color);
    void drawCross(QPainter *painter, int width, const QColor &color);
    void drawFancy(QPainter *painter, int width, const QColor &color);
    static void drawLed(QGraphicsScene *scene_, QPointF point);
};

#endif // DRAW_H
