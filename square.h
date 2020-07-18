#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure
{
    Q_OBJECT
public:
    Square(QObject *parent = 0);
    ~Square();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // SQUARE_H
