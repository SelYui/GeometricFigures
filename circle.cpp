#include "circle.h"

Circle::Circle(QObject *parent) :
    Figure(parent)
{
    // Начальное значение цвета
    color = Qt::blue;
}

Circle::~Circle()
{

}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(color);         // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawEllipse(-width/2,-height/2,width,height);   // Рисуем круг (координаты и ширина с высотой)

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
