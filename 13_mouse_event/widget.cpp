#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QString>
#include<QMouseEvent>
#include <QTimer>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setMouseTracking(true);

    timeId_1 = startTimer(1000);
    timeId_2 = startTimer(2000);

    QTimer* timer = new QTimer(this);

    timer->setInterval(500);
    timer->start();


    connect(timer, &QTimer::timeout, [=]{
       static int num =1;
       ui->label_4->setText(QString::number(num++));
    });

    connect(ui->pushButton,&QPushButton::clicked, [timer]{
        if(!timer->isActive()){
            qDebug() << "timer is not running";
            return;
        }
        timer->stop();
    });
    connect(ui->pushButton_2, &QPushButton::clicked, [timer]{
        if(timer->isActive()){
            qDebug() << "timer is running";
            return;
        }
        timer->start();
    });
}


Widget::~Widget()
{
    delete ui;
}



void Widget::timerEvent(QTimerEvent *e)
{
    static int num = 1;
    if(e->timerId() == timeId_1)
        ui->label_2->setText(QString::number(num++));
    else
        ui->label_3->setText(QString::number(num));
}
