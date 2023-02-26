#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPoint>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
//    QPainter painter(this);


//    painter.setBrush(Qt::cyan);
//    painter.setPen(Qt::darkBlue);

//    painter.drawLine(QPoint(0,0), QPoint(100,100));
//    painter.drawEllipse(QPoint(100,100),30,30);
//    painter.drawRect(QRect(QPoint(200,400), QPoint(600,800)));

//    painter.drawText(QRect(QPoint(600, 300), QPoint(700,400)), "青春没有售价，硬座直达拉萨");

    /////////////////////////高级设置
    QPainter painter(this);

    painter.drawEllipse(QPoint(100,100),200,200);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    painter.drawEllipse(QPoint(200,200),200,200);

    painter.drawRect(100,200,100,100);

    painter.save();
    painter.translate(100,100);
    painter.drawRect(100,200,100,100);

    painter.restore();
    painter.translate(100,100);
    painter.drawRect(100,200,100,100);
}
