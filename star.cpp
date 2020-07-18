#include "star.h"
#include "math.h"

Star::Star()
    : QGraphicsObject()
{
    angle = 0;     // Задаём угол поворота графического объекта
    setRotation(angle);     // Устанавилваем угол поворота графического объекта
    step = 5;       // Начальная величина изменения размера
    // Начальные значения высоты, ширины
    height = STAR_HEIGHT;
    width = STAR_WIDTH;
    // Начальное значение цвета
    color = Qt::yellow;
}

Star::~Star()
{

}

QRectF Star::boundingRect() const
{
    return QRectF(-150,-150,300,300);   // Ограничиваем область, в которой лежит фигура
}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // объявляем координаты точек
    int x_ext[NUMB_STAR], y_ext[NUMB_STAR], x_ins[NUMB_STAR], y_ins[NUMB_STAR];
    QPolygon polygon;           // Используем класс полигона, чтобы отрисовать фигуру

    // Находим координаты всех точек (xi = x0 + R*sin(Pi + 2*Pi*i/n); yi = y0 + R*cos(Pi + 2*Pi*i/n))
    for (int i = 0; i < NUMB_STAR; i++)
    {
        x_ext[i] = (width/2)*sin(M_PI+2*M_PI*i/NUMB_STAR);
        y_ext[i] = (height/2)*cos(M_PI+2*M_PI*i/NUMB_STAR);
        x_ins[i] = -(width/4)*sin(M_PI+2*M_PI*(3+i)/NUMB_STAR);
        y_ins[i] = -(height/4)*cos(M_PI+2*M_PI*(3+i)/NUMB_STAR);

        polygon << QPoint(x_ext[i], y_ext[i]) <<  QPoint(x_ins[i], y_ins[i]);           // Помещаем координаты точек в полигональную модель
    }

    painter->setBrush(QBrush(color));   // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawPolygon(polygon);      // Рисуем треугольник по полигональной модели

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Star::slotTimer()
{
    /* Поочерёдно выполняем проверку на нажатие клавиш
     * с помощью функции асинхронного получения состояния клавиш,
     * которая предоставляется WinAPI
     * */
    if(GetAsyncKeyState(VK_LEFT)){
        angle -= 5;         // Задаём поворот на 5 градусов влево
        setRotation(angle); // Поворачиваем объект
    }
    if(GetAsyncKeyState(VK_RIGHT)){
        angle += 5;         // Задаём поворот на 5 градусов вправо
        setRotation(angle); // Поворачиваем объект
    }
    if(GetAsyncKeyState(VK_SPACE)){
        // Изменяем цвет
        color = QColor(rand()%255, rand()%255, rand()%255);      // Рандомно формируем цвет
        update();       //обновляем фигуру с новыми параметрами
    }
    if(GetAsyncKeyState(VK_UP)){
        // Изменяем высоту height
        if(height >= STAR_HEIGHT)
        {
            height = STAR_HEIGHT;
            step = -step;
        }
        if(height <= 20)
        {
            height = 20;
            step = -step;
        }
        height += step;
        update();
    }
    if(GetAsyncKeyState(VK_DOWN)){
        // Изменяем ширину width
        if(width >= STAR_WIDTH)
        {
            width = STAR_WIDTH;
            step = -step;
        }
        if(width <= 20)
        {
            width = 20;
            step = -step;
        }
        width += step;
        update();
    }
}
