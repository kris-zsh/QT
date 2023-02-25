#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::eat()
{
    qDebug() << "走一起去吃饭吧 小明";
}

void Student::eat(QString food_name)
{
    qDebug() << "走 一起去吃" << food_name.toUtf8().data();
}
