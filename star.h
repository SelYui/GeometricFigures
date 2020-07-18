#ifndef STAR_H
#define STAR_H

#include <QObject>
#include <QGraphicsObject>
#include <QPainter>
#include <QGraphicsScene>

#include <QColor>
#include <QBrush>

#define NUMB_STAR 5
#define STAR_HEIGHT 300
#define STAR_WIDTH 300

/* Подключаем библиотеку, отвечающую за использование WinAPI
 * Данная библиотека необходима для асинхронной проверки состояния клавиш
 * */
#include <windows.h>

// Наследуемся от QGraphicsItem
class Star : public QGraphicsObject
{
    Q_OBJECT
public:
    Star();
    ~Star();

signals:

public slots:
    void slotTimer(); // Слот, который отвечает за обработку врщения фигуры

private:
    QRectF boundingRect() const;        // Область в которой лежит наша фигура
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);     // Реализуем отрисовку

    int step;                           // Шаг изменения размера
    int angle;      // Угол поворота графического объекта
    int height;     // Высота фигуры
    int width;      // Ширина фигуры
    QColor color;   // Цвет объекта

};

#endif // STAR_H
