#include "playscene.h"
#include <QMenuBar>
#include <QDebug>
#include <QString>
#include <QPainter>
#include <QPixmap>

PlayScene::PlayScene(QWidget *parent):QMainWindow(parent)
{

}

PlayScene::PlayScene(int level_index)
{
    level_index_ = level_index;

    QMenuBar* bar = menuBar();
    QMenu* menu = bar->addMenu("打开");
    QAction* action_quit = menu->addAction("退出");
    connect(action_quit, &QAction::triggered,[=]{
       this->close();
    });

    this->setWindowIcon(QIcon(":/picture/res/Coin0001.png"));
    this->setWindowTitle(QString("第%1").arg(QString::number(level_index)));
    this->setFixedSize(390,570);
}

void PlayScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap map(":/picture/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,map.width(), map.height(), map);

}
