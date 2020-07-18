#include "widget.h"
#include "ui_widget.h"

#include "triangle.h"
#include "square.h"
#include "circle.h"
#include "polygons.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(600,600);          // Задаем размеры виджета, то есть окна
    this->setFixedSize(600,600);    // Фиксируем размеры виджета

    scene = new QGraphicsScene();   // Инициализируем графическую сцену

    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали

    scene->setSceneRect(-250,-250,500,500); // Устанавливаем область графической сцены

//    scene->addLine(-250,0,250,0,QPen(Qt::black));   // Добавляем горизонтальную линию через центр
//    scene->addLine(0,-250,0,250,QPen(Qt::black));   // Добавляем вертикальную линию через центр

//    // Дополнительно нарисуем органичение территории в графической сцене
//    scene->addLine(-250,-250, 250,-250, QPen(Qt::black));
//    scene->addLine(-250, 250, 250, 250, QPen(Qt::black));
//    scene->addLine(-250,-250,-250, 250, QPen(Qt::black));
//    scene->addLine( 250,-250, 250, 250, QPen(Qt::black));

    // Создание кнопки с абсолютным позиционированием
    StarButton = new QPushButton("Star", ui->graphicsView);
    buttonPosition();       // Выставляем положение кнопки
    StarButton->hide();

    // Инициализируем таймер
    timer = new QTimer();

    // Начальное значение фигур и счетчиков
    figure = 0;         // Что бы не удалять несуществующие фигуры
    figureStar = 0;
    curButStar = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_TriangleButton_clicked()
{
    DrawFigure(triangle);
    curButStar |= 0x1;
}

void  Widget::on_SquareButton_clicked()
{
    DrawFigure(square);
    curButStar |= 0x2;
}

void  Widget::on_CircleButton_clicked()
{
    DrawFigure(circle);
    curButStar |= 0x4;
}

void Widget::on_TrapezoidButton_clicked()
{
    DrawFigure(trapezoid);
    curButStar |= 0x8;
}

void Widget::on_PentagonButton_clicked()
{
    DrawFigure(pentagon);
    curButStar |= 0x10;
}

void Widget::on_DodecagonButton_clicked()
{
    DrawFigure(dodecagon);
    curButStar |= 0x20;
}

void Widget::on_StarButton_clicked()
{
    DrawFigure(star);
}

void Widget::DrawFigure(FigureTypes typeFigure)
{
    slotAllDel();           // удаляем все не нужное со сцены

    if((curButStar&0x2F) == 0x2F)  // Показываем кнопку создания звезды
    {
        StarButton->show();
        curButStar = 0;
    }
    else
    {
        switch (typeFigure){
        case triangle: {
            figure = new Triangle();      // Инициализируем выбранную фигуру

            scene->addItem(figure);       // Добавляем фигуру на сцену
            figure->setPos(0,0);          // Устанавливаем фигуру в центр сцены

            // Вызываем слот обработки сигнала таймера.
            connect(timer, &QTimer::timeout, figure, &Figure::slotTimer);
            timer->start(1000 / 30);

            break;
        }
        case square: {
            figure = new Square();      // Инициализируем выбранную фигуру

            scene->addItem(figure);       // Добавляем фигуру на сцену
            figure->setPos(0,0);          // Устанавливаем фигуру в центр сцены

            // Вызываем слот обработки сигнала таймера.
            connect(timer, &QTimer::timeout, figure, &Figure::slotTimer);
            timer->start(1000 / 30);

            break;
        }
        case circle: {
            figure = new Circle();      // Инициализируем выбранную фигуру

            scene->addItem(figure);       // Добавляем фигуру на сцену
            figure->setPos(0,0);          // Устанавливаем фигуру в центр сцены

            // Вызываем слот обработки сигнала таймера.
            connect(timer, &QTimer::timeout, figure, &Figure::slotTimer);
            timer->start(1000 / 30);

            break;
        }
        case trapezoid: {
            figure = new Trapezoid();      // Инициализируем выбранную фигуру

            scene->addItem(figure);       // Добавляем фигуру на сцену
            figure->setPos(0,0);          // Устанавливаем фигуру в центр сцены

            // Вызываем слот обработки сигнала таймера.
            connect(timer, &QTimer::timeout, figure, &Figure::slotTimer);
            timer->start(1000 / 30);

            break;
        }
        case pentagon: {
            figure = new Pentagon();      // Инициализируем выбранную фигуру

            scene->addItem(figure);       // Добавляем фигуру на сцену
            figure->setPos(0,0);          // Устанавливаем фигуру в центр сцены

            // Вызываем слот обработки сигнала таймера.
            connect(timer, &QTimer::timeout, figure, &Figure::slotTimer);
            timer->start(1000 / 30);

            break;
        }
        case dodecagon: {
            figure = new Dodecagon();      // Инициализируем выбранную фигуру

            scene->addItem(figure);       // Добавляем фигуру на сцену
            figure->setPos(0,0);          // Устанавливаем фигуру в центр сцены

            // Вызываем слот обработки сигнала таймера.
            connect(timer, &QTimer::timeout, figure, &Figure::slotTimer);
            timer->start(1000 / 30);

            break;
        }
        case star: {
            figureStar = new Star();      // Инициализируем выбранную фигуру

            scene->addItem(figureStar);       // Добавляем фигуру на сцену
            figureStar->setPos(0,0);          // Устанавливаем фигуру в центр сцены

            // Вызываем слот обработки сигнала таймера.
            connect(timer, &QTimer::timeout, figureStar, &Star::slotTimer);
            timer->start(1000 / 30);

            break;
        }
        default: {
            break;
        }
        }
    }
}

void Widget::slotAllDel()
{

    // Перед созданием нового объекта останавливаем таймер
    timer->stop();

    // И удаляем все объекты со сцены, если они есть
    if(figure!=0)
    {
        figure->deleteLater();

        scene->removeItem(figure);   // Удаляем со сцены фигуру
        delete figure;               // Вообще удаляем
        figure = 0;
    }
    if(figureStar!=0)
    {
        figureStar->deleteLater();

        scene->removeItem(figureStar);   // Удаляем со сцены фигуру
        delete figureStar;               // Вообще удаляем
        figureStar = 0;
    }

    StarButton->hide();

}

void Widget::buttonPosition()
{

    // Устанавливаем в центр сцены
    StarButton->setGeometry({(289 - StarButton->geometry().width()/2),
                             (260 - StarButton->geometry().height()/2),
                             StarButton->geometry().width(),
                             StarButton->geometry().height()});
    //scene->addWidget(StarButton);

    // Вызываем слот обработки сигнала нажатия кнопки.
    connect(StarButton, &QPushButton::clicked, this, &Widget::on_StarButton_clicked);
}

