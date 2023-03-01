#include "chooselevelscene.h"
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QPixmap>
#include "mypushbutton.h"
#include <QDebug>
#include <QLabel>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    QMenuBar* bar = menuBar();
    setMenuBar(bar);

    QMenu* menu = bar->addMenu("打开");
    QAction* action_quit = menu->addAction("退出");

    connect(action_quit, &QAction::triggered, [=]{
        this->close();
    });

    this->setWindowIcon(QIcon(":/picture/res/Coin0001.png"));
    this->setWindowTitle("选择场景");
    this->setFixedSize(390,570);

    MyPushButton* button = new MyPushButton(":/picture/res/BackButton.png", ":/picture/res/BackButtonSelected.png");
    button->setParent(this);
    button->move(this->width() - button->width(), this->height()-  button->height());

    connect(button, &MyPushButton::clicked, [=]{
        qDebug() << "back clicked";
        //信号槽，然后主界面处理 返回
        emit this->backbutton();
    });

    for(int i = 0; i < 20; i++){

        MyPushButton* icon_button = new MyPushButton(":/picture/res/LevelIcon.png");
        icon_button->setParent(this);
        icon_button->move(60 + i % 4 * 60,180 + i / 4 * 60);

        QLabel* label = new QLabel(QString::number(i+1), this);
        label->setFixedSize(icon_button->width(), icon_button->height());
        label->move(60 + i % 4 * 60,180 + i / 4 * 60);

        //当 控件被覆盖的时候，可以指定这个macro  穿透事件，传给被覆盖的控件
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setAlignment(Qt::AlignCenter);

        //选择关卡
        connect(icon_button,&MyPushButton::clicked,[=]{
           QString str = QString("选择了第%1关卡").arg(QString::number(i+1));
            qDebug() << str;

            play_scene = new PlayScene(i + 1);

            this->hide();
            play_scene.show();

        });

        //在关卡界面 如果点击back则直接将窗口删除 显示原窗口
        connect(play_scene,&PlayScene::backbutton, [=]{

            if(play_scene == nullptr){
                delete play_scene;
                play_scene = nullptr;
            }
            this->show();
        });
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPixmap map(":/picture/res/PlayLevelSceneBg.png");
    QPainter painter(this);

    painter.drawPixmap(0,0, map.width(), map.height(),map);

    QPixmap title(":/picture/res/Title.png");
    painter.drawPixmap(20,10,title);
}
