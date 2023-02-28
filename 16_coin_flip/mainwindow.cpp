#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QPixmap>
#include <MyPushButton.h>

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

    MyPushButton* my_push_button = new MyPushButton(":/picture/res/MenuSceneStartButton.png");
    my_push_button->setParent(this);

    my_push_button->move((this->width() - my_push_button->width()) * 0.5, this->height() * 0.7);

    connect(my_push_button, &MyPushButton::clicked, [=]{
       qDebug() << "clicked";
       my_push_button->moveDown();
       my_push_button->moveUp();

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
