#ifndef PlayScene1_H
#define PlayScene1_H

#include <QMainWindow>
#include "dataconfig.h"
#include <QVector>
#include <mycoin.h>
#include <QPropertyAnimation>
#include <QLabel>

class PlayScene1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene1(QWidget *parent = 0);
    explicit PlayScene1(int idx);
    void paintEvent(QPaintEvent *);

private:
    int idx_;
    QVector<QVector<MyCoin*>> coin_arr;
    QLabel* success;
    QPixmap map_suceess;
    void MoveDown();
signals:
    void backbutton();
public slots:
};

#endif // PlayScene1_H
