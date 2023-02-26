#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);

    void mouseMoveEvent(QMouseEvent *ev)override;
    void mousePressEvent(QMouseEvent *ev)override;
    void mouseReleaseEvent(QMouseEvent *ev)override;

    bool event(QEvent *e) override;

signals:

public slots:
};

#endif // MYLABEL_H
