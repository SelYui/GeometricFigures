#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

// Наследуемся от Figure
class Triangle : public Figure
{
    Q_OBJECT
public:
    Triangle(QObject *parent = 0);
    ~Triangle();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);     // Реализуем отрисовку
};

#endif // TRIANGLE_H
