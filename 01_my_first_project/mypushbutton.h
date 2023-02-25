#ifndef MYQUSHBUTTON_H
#define MYQUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = 0);
    ~MyPushButton();
signals:

public slots:
};

#endif // MYQUSHBUTTON_H
