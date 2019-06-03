#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsItem>
#include <QPainter>

class Square : public QGraphicsItem
{
public:
    Square();
    ~Square();

protected:
    QRectF boundingRect() const;    /* Определяем виртуальный метод,
                                     * который возвращает область, в которой
                                     * находится треугольник
                                     * */
    /* Определяем метод для отрисовки треугольника
     * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SQUARE_H
