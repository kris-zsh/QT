#include "my_widget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* button1 = new QPushButton;
    QPushButton* button2 = new QPushButton;
    MyPushButton* button3 = new MyPushButton;
    //给按钮设计父窗口，在父窗口进行显式
    button1->setParent(this);
    button2->setParent(this);
    button3->setParent(this);
    //设置按钮文本
    button1->setText("树昊辛苦了");
    button2->setText("晚上好");
    button3->setText("QT加油");

    //设置按钮位置
    button1->move(200,200);
    button3->move(100,100);
    //设置按钮大小
    button1->resize(200,100);
    button2->resize(200,100);
    //设置主窗口大小并 固定大小
//    this->resize(600,400);
    this->setFixedSize(600,400);

    this->setWindowTitle("树昊的第一个QT程序");
//    connect(button3, &MyPushButton::clicked, this, &myWidget::close);
    connect(button3, &QPushButton::clicked, this, &QWidget::close);
}

myWidget::~myWidget()
{
    qDebug() << "~mydget";
}
