#include "square.h"

Square::Square(QObject *parent) :
    Figure(parent)
{
    // Начальное значение цвета
    color = Qt::green;
}

Square::~Square()
{

}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(color);         // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawRect(-width/2,-height/2,width,height);   // Рисуем прямоугольник (координаты и ширина с высотой)

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
