#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = 0);
    MyPushButton(QString normaled, QString pressed = "");

    void moveDown();
    void moveUp();
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    QString normaled_;
    QString pressed_;
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
