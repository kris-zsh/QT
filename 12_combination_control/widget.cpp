#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, [=]{
        qDebug() <<"进度条1："<< ui->widget->getValue();
        qDebug() <<"进度条2："<< ui->widget_2->getValue();
    });


    connect(ui->pushButton_2, &QPushButton::clicked, [=]{
        QString text = ui->lineEdit->text();
        qDebug() << "用户输入：" << text;
        bool ok = false;
        int num = text.toInt(&ok);
        if(!ok){
            qDebug() << "用户输入非数字，直接退出";
            return;
        }

        ui->widget->setValue(num);
        ui->widget_2->setValue(num);
    });
}

Widget::~Widget()
{
    delete ui;
}
