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


//    connect(button, &QAbstractButton::clicked, this, &Widget::ClassIsOver);

      //使用信号 链接槽 然后在发射信号
//    void(Teacher:: * hungry_)(QString) = &Teacher::Myhungry;
//    void(Student:: * eat_)(QString) = &Student::eat;
//    connect(teacher_, hungry_, student_, eat_);
//    connect(teacher_, SIGNAL(Myhungry(QString)), student_, SLOT(eat(QString)));


    //使用信号链接信号
    void(Teacher:: * hungry_)(void) = &Teacher::Myhungry;
    void(Student:: * eat_)(void) = &Student::eat;
    connect(button, &QAbstractButton::clicked, teacher_, hungry_);

    connect(teacher_, SIGNAL(Myhungry()), student_, SLOT(eat()));

}

Widget::~Widget()
{

}

void Widget::ClassIsOver()
{
    qDebug() << "下课铃声响起";
    emit teacher_->Myhungry("第六季");
}
