#include "square.h"

Square::Square() :
    QGraphicsItem()
{

}

Square::~Square()
{

}

QRectF Square::boundingRect() const
{
    return QRectF(-50,-50,50,50);   // Ограничиваем область, в которой лежит треугольник
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;   // Используем класс полигона, чтобы отрисовать квадрат
        // Помещаем координаты точек в полигональную модель
        polygon << QPoint(0,0) << QPoint(10,0) << QPoint(10,10) << QPoint(0,10);
        painter->setBrush(Qt::green);     // Устанавливаем кисть, которой будем отрисовывать объект
        painter->drawPolygon(polygon);  // Рисуем квадрат по полигональной модели
        Q_UNUSED(option);
        Q_UNUSED(widget);
}
