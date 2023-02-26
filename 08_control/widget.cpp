#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QListWidgetItem>
#include <QStringList>
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

    QListWidgetItem* widgetItem = new QListWidgetItem("锄禾日当午");
    ui->listWidget->addItem(widgetItem);
    ui->listWidget->addItem("汗滴禾下土");

    QStringList list;
    list << "谁知盘中餐" << "粒粒皆辛苦";
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}
