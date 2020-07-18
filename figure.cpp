#include "figure.h"

Figure::Figure(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    angle = 0;     // Задаём угол поворота графического объекта
    setRotation(angle);     // Устанавилваем угол поворота графического объекта
    step = 5;       // Начальная величина изменения размера
    // Начальные значения высоты, ширины
    height = FIGURE_HEIGHT;
    width = FIGURE_WIDTH;
}

Figure::~Figure()
{

}

QRectF Figure::boundingRect() const
{
    return QRectF(-150,-150,300,300);   // Ограничиваем область, в которой лежит фигура
}

void Figure::slotTimer()
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
        if(height >= FIGURE_HEIGHT)
        {
            height = FIGURE_HEIGHT;
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
        if(width >= FIGURE_WIDTH)
        {
            width = FIGURE_WIDTH;
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
