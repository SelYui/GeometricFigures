#include "triangle.h"

Triangle::Triangle(QObject *parent) :
    Figure(parent)
{
    // Начальное значение цвета
    color = Qt::red;
}

Triangle::~Triangle()
{

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;           // Используем класс полигона, чтобы отрисовать треугольник
    // Помещаем координаты точек в полигональную модель
    polygon << QPoint(0,-height/2) << QPoint(width/2,height/4) << QPoint(-width/2,height/4);
    painter->setBrush(QBrush(color));   // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawPolygon(polygon);      // Рисуем треугольник по полигональной модели

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
