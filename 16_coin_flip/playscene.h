#ifndef PlayScene1_H
#define PlayScene1_H

#include <QMainWindow>
#include "dataconfig.h"
#include <QVector>

class PlayScene1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene1(QWidget *parent = 0);
    explicit PlayScene1(int idx);
    void paintEvent(QPaintEvent *);

private:
    int idx_ = 0;
    QVector< QVector<int>> cur_section_;
signals:
    void backbutton();
public slots:
};

#endif // PlayScene1_H
