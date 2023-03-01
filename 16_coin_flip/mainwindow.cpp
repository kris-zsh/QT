#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QPixmap>
#include <MyPushButton.h>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionQuit, &QAction::triggered, [this]{
       this->close();
    });

    this->setFixedSize(390,570);
    this->setWindowIcon(QIcon(":/picture/res/Coin0001.png"));
    this->setWindowTitle("IconFlip");

    choose_level_scene = new ChooseLevelScene;

    MyPushButton* my_push_button = new MyPushButton(":/picture/res/MenuSceneStartButton.png");
    my_push_button->setParent(this);

    my_push_button->move((this->width() - my_push_button->width()) * 0.5, this->height() * 0.7);

    connect(my_push_button, &MyPushButton::clicked, [=]{
       qDebug() << "clicked";
       my_push_button->moveDown();
       my_push_button->moveUp();

       QTimer::singleShot(400,[=]{
        this->hide();
        choose_level_scene->show();
       });
    });

    connect(choose_level_scene,&ChooseLevelScene::backbutton, [=]{
        choose_level_scene->hide();
        this->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    QPixmap background(":/picture/res/PlayLevelSceneBg.png");

    painter.drawPixmap(0,0,background.width(), background.height(),background);

    QPixmap icon(":/picture/res/Title.png");
    painter.drawPixmap(40,40,icon.width() * 0.5, icon.height()*0.5, icon);
}
