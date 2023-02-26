#include "widget.h"
#include "ui_widget.h"
#include <QStringList>
#include <QTableWidgetItem>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<< "英雄名" << "性别" << "年龄");
    ui->tableWidget->setRowCount(5);

    QStringList name;
    name << "亚瑟" << "妲己" << "赵云" << "李广" << "霍去病";
    QStringList sex;
    sex << "男" << "女";
    QStringList age;
    age << "20" << "30" << "40" << "50" << "60";
    for(int i = 0; i < 5; i++){
        int column = 0;
        QString cur_sex = i % 2 == 0 ? sex[0] : sex[1];

        ui->tableWidget->setItem(i,column++, new QTableWidgetItem(name[i]));
        ui->tableWidget->setItem(i, column++, new QTableWidgetItem(cur_sex));
        ui->tableWidget->setItem(i, column++, new QTableWidgetItem(age[i]));
    }

}

Widget::~Widget()
{
    delete ui;
}
