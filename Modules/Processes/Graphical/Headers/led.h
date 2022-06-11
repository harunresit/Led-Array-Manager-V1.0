#ifndef LED_H
#define LED_H

#include <QColor>
#include <QGraphicsItem>
#include <QObject>

//This class will create led image items

class Led : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Led(const QColor &color, int x, int y);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    int returnNum();
    int returnX();
    int returnY();

    ///Modified
    void setNumber(int num);

    void setColor(QColor &color);

signals:
    void viewPressed(Led*);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int x;
    int y;
    QColor color;
    QVector<QPointF> stuff;

    //Modified
    int previousitem_x = 0;
    int previousitem_y = 0;
    int number = 0;

};



#endif // LED_H
