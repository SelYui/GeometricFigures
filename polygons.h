#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

// Наследуемся от Figure
class Trapezoid : public Figure
{
    Q_OBJECT
public:
    Trapezoid(QObject *parent = 0);
    ~Trapezoid();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);     // Реализуем отрисовку
};

#endif // TRAPEZOID_H
///////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"

// Наследуемся от Figure
class Pentagon : public Figure
{
    Q_OBJECT
public:
    Pentagon(QObject *parent = 0);
    ~Pentagon();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);     // Реализуем отрисовку
};

#endif // PENTAGON_H
///////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DODECAGON_H
#define DODECAGON_H

#include "figure.h"

// Наследуемся от Figure
class Dodecagon : public Figure
{
    Q_OBJECT
public:
    Dodecagon(QObject *parent = 0);
    ~Dodecagon();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);     // Реализуем отрисовку
};

#endif // DODECAGON_H
