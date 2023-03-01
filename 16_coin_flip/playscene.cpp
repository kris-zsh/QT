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

    QLabel* label = new QLabel(this);
    QFont font;

    font.setFamily("华文新魏");
    font.setPointSize(10);
    label->setFont(font);
    label->setText(QString("Level: %1").arg(QString::number(idx_)));
    label->setGeometry(QRect(30, this->height() - 50,120, 50));

    dataConfig data;
    cur_section_ = data.mData[idx_];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            QLabel* label = new QLabel(this);
            QPixmap map(":/picture/res/BoardNode(1).png");

            label->setFixedSize(map.width(), map.height());

            label->setPixmap(map);

            label->move(87 + i*50,200+j*50);

            QString image = cur_section_[i][j] == 1 ? ":/picture/res/Coin0001.png" : ":/picture/res/Coin0008.png";
            MyCoin* coin = new MyCoin(image);
            coin->move(90 + i*48,202+j*48);
            coin->setParent(this);

        }
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
