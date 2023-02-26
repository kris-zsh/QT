#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void mouseMoveEvent(QMouseEvent *ev)override;
    void mousePressEvent(QMouseEvent *ev)override;
    void mouseReleaseEvent(QMouseEvent *ev)override;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
