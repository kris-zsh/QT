#include "PlayScene.h"
#include <QMenuBar>
#include <mypushbutton.h>
#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QFont>
#include <dataconfig.h>
#include <mycoin.h>
#include <QString>
PlayScene1::PlayScene1(QWidget *parent) : QMainWindow(parent)
{

}

PlayScene1::PlayScene1(int idx)
{
    idx_=  idx;

    QMenuBar* bar = menuBar();
    setMenuBar(bar);

    QMenu* menu = bar->addMenu("打开");
    QAction* action_quit = menu->addAction("退出");

    connect(action_quit, &QAction::triggered, [=]{
        this->close();
    });

    this->setWindowIcon(QIcon(":/picture/res/Coin0001.png"));
    this->setWindowTitle(QString("第%1关").arg(QString::number(idx_)));
    this->setFixedSize(390,570);

    MyPushButton* button = new MyPushButton(":/picture/res/BackButton.png", ":/picture/res/BackButtonSelected.png");
    button->setParent(this);
    button->move(this->width() - button->width(), this->height()-  button->height());

    connect(button, &MyPushButton::clicked, [=]{
        qDebug() << "back clicked";
        //信号槽，然后主界面处理 返回
        emit this->backbutton();
    });

    MyCoin::is_active = false;

    QLabel* label = new QLabel(this);
    QFont font;

    font.setFamily("华文新魏");
    font.setPointSize(10);
    label->setFont(font);
    label->setText(QString("Level: %1").arg(QString::number(idx_)));
    label->setGeometry(QRect(30, this->height() - 50,120, 50));

    dataConfig data;

    success = new QLabel(this);
    map_suceess.load(":/picture/res/LevelCompletedDialogBg.png");
    success->setPixmap(map_suceess);
    success->setGeometry((this->width() - map_suceess.width()) * 0.5 ,-map_suceess.height(),map_suceess.width(), map_suceess.height());


    for(int i = 0; i < 4; i++){
        QVector<MyCoin*>temp;
        for(int j = 0; j < 4; j++){

            int is_gold =dataConfig::mData[idx_][i][j];
            QLabel* label = new QLabel(this);
            QPixmap map(":/picture/res/BoardNode(1).png");

            label->setFixedSize(map.width(), map.height());

            label->setPixmap(map);

            label->move(87 + i*50,200+j*50);

            QString image = is_gold == 1 ? ":/picture/res/Coin0001.png" : ":/picture/res/Coin0008.png";
            MyCoin* coin = new MyCoin(image,is_gold);

            coin->move(90 + i*48,202+j*48);
            coin->setParent(this);
            temp.push_back(coin);

            connect(coin,&MyCoin::clicked,[=]{
               coin->reverse_coin();

               QTimer::singleShot(400,[=]{
                   if(i > 0)
                     coin_arr[i-1][j]->reverse_coin();
                   if(i < 3)
                     coin_arr[i + 1][j]->reverse_coin();
                   if(j > 0)
                     coin_arr[i][j-1]->reverse_coin();
                   if(j < 3)
                     coin_arr[i][j + 1]->reverse_coin();

                   bool isWin = true;
                   for(QVector<MyCoin*> coin_: coin_arr){
                       for(MyCoin* c: coin_)
                           if(!c->isGold()) isWin = false;
                   }

                   if(isWin){
                       qDebug() << "is Win";
                       MoveDown();
                       MyCoin::is_active = true;
                   }
               });

            });
        }
        coin_arr.push_back(temp);
    }
}

void PlayScene1::paintEvent(QPaintEvent *)
{
    QPixmap map(":/picture/res/PlayLevelSceneBg.png");
    QPainter painter(this);

    painter.drawPixmap(0,0, map.width(), map.height(),map);

    QPixmap title(":/picture/res/Title.png");
    painter.drawPixmap(20,10,title);
}

void PlayScene1::MoveDown()
{
    QPropertyAnimation *animation = new QPropertyAnimation(success, "geometry");
     animation->setDuration(200);
     animation->setEasingCurve(QEasingCurve::InQuart);
     animation->setStartValue(QRect((this->width() - map_suceess.width()) * 0.5 ,-map_suceess.height(),map_suceess.width(), map_suceess.height()));
     animation->setEndValue(QRect((this->width() - map_suceess.width()) * 0.5 ,40,map_suceess.width(), map_suceess.height()));

     animation->start();
}
