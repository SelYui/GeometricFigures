#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure
{
    Q_OBJECT
public:
    Circle(QObject *parent = 0);
    ~Circle();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // CIRCLE_H
