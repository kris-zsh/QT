#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "playscene.h"


class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
private:
    PlayScene1 *play_scene = nullptr;
signals:
    void backbutton();
public slots:
};

#endif // PLAYSCENE_H
