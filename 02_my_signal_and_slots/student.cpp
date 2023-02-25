#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::eat()
{
    qDebug() << "走一起去吃饭吧 小明";
}
