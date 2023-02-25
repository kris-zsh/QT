#include "widget.h"

#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    QAbstractButton* button = new QPushButton("下课了",this);

    student_ = new Student(this);
    teacher_ = new Teacher(this);

    this->setFixedSize(600,400);
    button->resize(200, 200);
    button->move(100,100);

    connect(button, &QAbstractButton::clicked, this, &Widget::ClassIsOver);
    connect(teacher_, &Teacher::Myhungry, student_, &Student::eat);
}

Widget::~Widget()
{

}

void Widget::ClassIsOver()
{
    qDebug() << "下课铃声想起";
    emit teacher_->Myhungry();
}
