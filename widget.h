#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QPushButton>

#include "figure.h"
#include "star.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //int typeFigure; // Текущий тип фигуры

    // перечисление типов
    enum FigureTypes{
        triangle,
        square,
        circle,
        trapezoid,
        pentagon,
        dodecagon,
        star
    };

private:
    void buttonPosition();      // Позиция кнопки на сцене

    Ui::Widget *ui;
    QGraphicsScene  *scene;     // Объявляем графическую сцену
    QTimer          *timer;     /* Объявляем таймер, благодаря которому
                                 * будет производиться изменения положения объекта на сцене
                                 * При воздействии на него клавишами клавиатуры
                                 * */
    Figure          *figure;    // Рисуемый объект
    Star            *figureStar;// Рисуем звезду
    QPushButton     *StarButton;// Кнопка для создания треугольника

    int             curButStar; // Признак нажатия кнопки

private slots:
    void slotAllDel();              // Удаление всех объектов со сцены перед добавлением нового
    void DrawFigure(FigureTypes typeFigure);
    void on_TriangleButton_clicked();       // Создание треугольника
    void on_SquareButton_clicked();         // Создание квадрата
    void on_CircleButton_clicked();         // Создание круга
    void on_TrapezoidButton_clicked();      // Создание трапеции
    void on_PentagonButton_clicked();       // Создание пятиугольника
    void on_DodecagonButton_clicked();      // Создание двенадцатиугольника
    void on_StarButton_clicked();           // Создание звезды

};
#endif // WIDGET_H
