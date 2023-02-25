#include "mypushbutton.h"
#include <QPushButton>
#include <QDebug>
MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "construct MypushButton";
}

MyPushButton::~MyPushButton()
{
    qDebug() << "~MyPushButton\n";
}
