#include "widget.h"
#include "ui_widget.h"
#include <QTreeWidgetItem>
#include <QStringList>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "简介");

    QTreeWidgetItem* powerItem = new QTreeWidgetItem(QStringList() << "力量" << "血厚");
    QTreeWidgetItem* fastItem = new QTreeWidgetItem(QStringList() << "敏捷" << "攻击力高");
    QTreeWidgetItem* SmartItem = new QTreeWidgetItem(QStringList() << "智力" << "蓝多");

    QList<QTreeWidgetItem*>list = {powerItem, fastItem, SmartItem};
    ui->treeWidget->addTopLevelItems(list);

    powerItem->addChild(new QTreeWidgetItem(QStringList() << "曹洪" << "就是冲"));
    powerItem->addChild(new QTreeWidgetItem(QStringList() << "许褚" << "野猪冲撞"));

    fastItem->addChild(new QTreeWidgetItem(QStringList() << "马岱" << "远程普a"));
    fastItem->addChild(new QTreeWidgetItem(QStringList() << "吕布" << "开大无敌"));

    SmartItem->addChild(new QTreeWidgetItem(QStringList() << "鲁肃" << "原地装死"));
    SmartItem->addChild(new QTreeWidgetItem(QStringList() << "程普" << "树林老六"));

}


Widget::~Widget()
{
    delete ui;
}
