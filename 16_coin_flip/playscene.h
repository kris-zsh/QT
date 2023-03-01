#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = 0);
    explicit PlayScene(int idx);
    void paintEvent(QPaintEvent *);

private:
    int idx_;
signals:
    void backbutton();
public slots:
};

#endif // PLAYSCENE_H
