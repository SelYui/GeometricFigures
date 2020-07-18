#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

#include <QColor>
#include <QBrush>

#define NUMB_PENT       5
#define NUMB_DODEC      12
#define FIGURE_HEIGHT   200
#define FIGURE_WIDTH    200

/* Подключаем библиотеку, отвечающую за использование WinAPI
 * Данная библиотека необходима для асинхронной проверки состояния клавиш
 * */
#include <windows.h>

// Наследуемся от QGraphicsItem
class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Figure(QObject *parent = 0);
    ~Figure();

    int angle;      // Угол поворота графического объекта
    int height;     // Высота фигуры
    int width;      // Ширина фигуры
    QColor color;   // Цвет объекта


signals:

public slots:
    void slotTimer(); // Слот, который отвечает за обработку врщения фигуры

private:
    QRectF boundingRect() const;        // Область в которой лежит наша фигура
    int step;                           // Шаг изменения размера

};

#endif // FIGURE_H
