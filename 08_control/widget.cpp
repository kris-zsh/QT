#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(true);
    connect(ui->radioButton_2, &QRadioButton::clicked, []{
        qDebug() << "女被点击了";
    });

    connect(ui->commandLinkButton,&QCommandLinkButton::clicked,[](){
        qDebug() << "link button 点击了";
    });
}

Widget::~Widget()
{
    delete ui;
}
