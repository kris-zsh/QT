#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = 0);
    explicit PlayScene(int level_index);

    void paintEvent(QPaintEvent *);
private:
    int level_index_;
signals:

public slots:
};

#endif // PLAYSCENE_H
