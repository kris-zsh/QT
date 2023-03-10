#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimerEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void timerEvent(QTimerEvent *e);
    bool eventFilter(QObject *obj, QEvent *event);
private:
    Ui::Widget *ui;
    int timeId_1 = 0;
    int timeId_2 =0;
};

#endif // WIDGET_H
