#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = 0);

signals:

     void Myhungry();
     void Myhungry(QString eat_name);
public slots:
};

#endif // TEACHER_H
