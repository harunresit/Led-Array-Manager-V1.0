#include "Modules/Processes/Graphical/Headers/draw.h"
#include "Modules/Processes/Graphical/Headers/led.h"

Draw::Draw()
{

}

void Draw::drawSquare(QPainter *painter, int width, const QColor &color)
{
    painter->setPen(color);
    painter->drawLine(0, 0, width, 0);
    painter->drawLine(0, 0, 0, width);
}

void Draw::drawCross(QPainter *painter, int width, const QColor &color)
{
    painter->setPen(color);
    painter->drawLine(0, 0, 2, 0);
    painter->drawLine(0, 0, 0, 2);
    painter->drawLine(0, width - 1, 0, width);
    painter->drawLine(width - 1, 0, width, 0);
}

void Draw::drawFancy(QPainter *painter, int width, const QColor &color)
{
    int halfWidth = 0.5*width + 0.5;

    painter->setPen(color.lighter(106));
    painter->drawLine(0, halfWidth, width, halfWidth);
    painter->drawLine(halfWidth, 0, halfWidth, width);
    painter->setPen(color);
    painter->drawLine(0, 0, width, 0);
    painter->drawLine(0, 0, 0, width);
    painter->setPen(color.darker(118));
    painter->drawPoint(halfWidth, halfWidth);
    painter->setPen(color.darker(160));
    painter->drawPoint(0, 0);
}

void Draw::drawLed(QGraphicsScene *scene_, QPointF point)
{
    /*
    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);
    blackPen.setWidth(6);

    scene_->addRect(point.x(),point.y(),100,100,blackPen,redBrush);
    qDebug() << point << endl; */
    QGraphicsItem *item = new Led(QColor(216,15,15),0,1);
    item->setPos(point);
    scene_->addItem(item);
}

QPixmap Draw::drawPattern(int type, int step, const QColor &color)
{
    QPixmap pixmap(step, step);
    QPainter painter;
    int pixmapWidth = pixmap.width() - 1;

    pixmap.fill(Qt::transparent);

    painter.begin(&pixmap);

    switch (type) {
    case 0:
        drawSquare(&painter, pixmapWidth, color);
        break;
    case 1:
        drawCross(&painter, pixmapWidth, color);
        break;
    case 2:
        drawFancy(&painter, pixmapWidth, color);
        break;
        }

    return pixmap;
}
