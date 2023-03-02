#include "mycoin.h"
#include <QPixmap>
#include <QDebug>

bool MyCoin::is_active = false;

MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
{

}

MyCoin::MyCoin(QString image, int is_gold)
{
    image_ = image;
    is_gold_ = is_gold;

    timer1 = new QTimer(this);
    timer1->setInterval(40);

    timer2 = new QTimer(this);
    timer2->setInterval(40);

    QPixmap map(image);
    this->setFixedSize(map.width(), map.height());
    this->setStyleSheet("QPushButton:{border:0px;}");
    this->setIcon(map);
    this->setIconSize(QSize(map.width(), map.height()));

    connect(timer1,&QTimer::timeout,[=]{
        QPixmap map(QString(":/picture/res/Coin000%1.png").arg(cur++));

        this->setFixedSize(map.width(), map.height());
        this->setStyleSheet("QPushButton:{border:0px;}");
        this->setIcon(map);
        this->setIconSize(QSize(map.width(), map.height()));
        if(cur == 9){
//            is_active = false;
            timer1->stop();
        }
    });

    connect(timer2,&QTimer::timeout,[=]{
        QPixmap map(QString(":/picture/res/Coin000%1.png").arg(cur--));

        this->setFixedSize(map.width(), map.height());
        this->setStyleSheet("QPushButton:{border:0px;}");
        this->setIcon(map);
        this->setIconSize(QSize(map.width(), map.height()));
        if(cur == 0){
//            is_active = false;
            timer2->stop();
        }
    });
}

void MyCoin::reverse_coin()
{
    qDebug() << "reverse_coin";
    if(is_active)
        return;

//    is_active = true;

    if(is_gold_){
        cur = 1;
        timer1->start();
    }
    else{
        cur = 8;
        timer2->start();
    }

    is_gold_ = !is_gold_;
}

bool MyCoin::isGold()
{
    return is_gold_;
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(is_active){
       return;
    }
    QPushButton::mousePressEvent(e);
}

