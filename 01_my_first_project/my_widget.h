#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QWidget>

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();
};

#endif // MY_WIDGET_H
