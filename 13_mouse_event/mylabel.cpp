#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>
#include <QString>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
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

void MyLabel::mousePressEvent(QMouseEvent *ev)
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

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
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

bool MyLabel::event(QEvent *e)
{
    if(e->type() == QEvent::MouseMove){
        QMouseEvent* ev = dynamic_cast<QMouseEvent*>(e);
        QString context = QString("event move x = %1, y = %2, gx = %3, gy = %4").
                arg(ev->x()).
                arg(ev->y()).
                arg(ev->globalX()).
                arg(ev->globalY());
        qDebug() << context;
        return true;
    }
}
