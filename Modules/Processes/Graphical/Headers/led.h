#ifndef LED_H
#define LED_H

#include <QColor>
#include <QGraphicsItem>

//This class will create led image items

class Led : public QGraphicsItem
{
public:
    Led(const QColor &color, int x, int y);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int x;
    int y;
    QColor color;
    QVector<QPointF> stuff;
};



#endif // LED_H
