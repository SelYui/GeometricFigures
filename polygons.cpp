#include "polygons.h"
#include "math.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Trapezoid::Trapezoid
/// \param parent
///
Trapezoid::Trapezoid(QObject *parent) :
    Figure(parent)
{
    // Начальное значение цвета
    color = Qt::darkRed;
}

Trapezoid::~Trapezoid()
{

}

void Trapezoid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;           // Используем класс полигона, чтобы отрисовать фигуру
    // Помещаем координаты точек в полигональную модель
    polygon << QPoint(-width/4,-height/4) << QPoint(width/4,-height/4) << QPoint(width/2,height/2) << QPoint(-width/2,height/2);
    painter->setBrush(QBrush(color));   // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawPolygon(polygon);      // Рисуем треугольник по полигональной модели

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Pentagon::Pentagon
/// \param parent
///
Pentagon::Pentagon(QObject *parent) :
    Figure(parent)
{
    // Начальное значение цвета
    color = Qt::darkGreen;
}

Pentagon::~Pentagon()
{

}

void Pentagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // объявляем координаты точек
    int x[NUMB_PENT], y[NUMB_PENT];
    QPolygon polygon;           // Используем класс полигона, чтобы отрисовать фигуру

    // Находим координаты всех точек (xi = x0 + R*sin(Pi + 2*Pi*i/n); yi = y0 + R*cos(Pi + 2*Pi*i/n))
    for (int i = 0; i < NUMB_PENT; i++)
    {
        x[i] = (width/2)*sin(M_PI+2*M_PI*i/NUMB_PENT);
        y[i] = (height/2)*cos(M_PI+2*M_PI*i/NUMB_PENT);

        polygon << QPoint(x[i],y[i]);           // Помещаем координаты точек в полигональную модель
    }

    painter->setBrush(QBrush(color));   // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawPolygon(polygon);      // Рисуем треугольник по полигональной модели

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dodecagon::Dodecagon
/// \param parent
///
Dodecagon::Dodecagon(QObject *parent) :
    Figure(parent)
{
    // Начальное значение цвета
    color = Qt::darkBlue;
}

Dodecagon::~Dodecagon()
{

}

void Dodecagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // объявляем координаты точек
    int x[NUMB_DODEC], y[NUMB_DODEC];
    QPolygon polygon;           // Используем класс полигона, чтобы отрисовать фигуру

    // Находим координаты всех точек (xi = x0 + R*sin(Pi + 2*Pi*i/n); yi = y0 + R*cos(Pi + 2*Pi*i/n))
    for (int i = 0; i < NUMB_DODEC; i++)
    {
        x[i] = (width/2)*sin(M_PI+2*M_PI*i/NUMB_DODEC);
        y[i] = (height/2)*cos(M_PI+2*M_PI*i/NUMB_DODEC);

        polygon << QPoint(x[i],y[i]);           // Помещаем координаты точек в полигональную модель
    }

    painter->setBrush(QBrush(color));   // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawPolygon(polygon);      // Рисуем треугольник по полигональной модели

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

