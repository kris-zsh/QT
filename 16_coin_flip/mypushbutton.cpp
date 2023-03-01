#include "mypushbutton.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>
#include <QMouseEvent>
MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

MyPushButton::MyPushButton(QString normaled, QString pressed)
{
    normaled_ = normaled;
    pressed_ = pressed;

    QPixmap map(normaled);

    this->setFixedSize(map.width(), map.height());

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(map);

    this->setIconSize(QSize(map.width(), map.height()));

}

void MyPushButton::moveDown()
{
     QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
     animation->setDuration(200);

     animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
     animation->setEndValue(QRect(this->x(), this->y() + 5, this->width(), this->height()));

     animation->start();
}

void MyPushButton::moveUp()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
     animation->setDuration(200);

     animation->setStartValue(QRect(this->x(), this->y() + 5, this->width(), this->height()));
     animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

     animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(!pressed_.isEmpty()){

        QPixmap map(pressed_);

        this->setFixedSize(map.width(), map.height());

        this->setIcon(map);

        this->setIconSize(QSize(map.width(), map.height()));
    }
    QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(!pressed_.isEmpty()){
        QPixmap map(normaled_);

        this->setFixedSize(map.width(),map.height());

        this->setIcon(map);

        this->setIconSize(QSize(map.width(), map.height()));

    }
    QPushButton::mouseReleaseEvent(e);
}
