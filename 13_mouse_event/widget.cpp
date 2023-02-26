#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QString>
#include<QMouseEvent>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() != Qt::RightButton)
        return;
    QString context = QString("move x = %1, y = %2, gx = %3, gy = %4").
            arg(ev->x()).
            arg(ev->y()).
            arg(ev->globalX()).
            arg(ev->globalY());
    qDebug() << context;
}

void Widget::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons() != Qt::LeftButton)
        return;
    QString context = QString("press x = %1, y = %2, gx = %3, gy = %4").
            arg(ev->x()).
            arg(ev->y()).
            arg(ev->globalX()).
            arg(ev->globalY());
    qDebug() << context;
}

void Widget::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() != Qt::LeftButton)
        return;
    QString context = QString("release x = %1, y = %2, gx = %3, gy = %4").
            arg(ev->x()).
            arg(ev->y()).
            arg(ev->globalX()).
            arg(ev->globalY());
    qDebug() << context;
}
