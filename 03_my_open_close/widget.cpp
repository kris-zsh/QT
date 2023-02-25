#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* open = new QPushButton("open", this);
//    QPushButton* close = new QPushButton("close", this);

    open->setFixedSize(100,100);
//    close->setFixedSize(100,100);
    this->setFixedSize(600,400);

//    close->move(100,0);

//    close->setEnabled(false);
    QPushButton* windows = new QPushButton("hello");

    connect(open, &QPushButton::clicked, [=]{
        if(open->text() == "open"){
            windows->show();
            open->setText("close");
        }
        else{
            windows->close();
            open->setText("open");
        }

//        close->setEnabled(true);
//        open->setEnabled(false);
    });

//    connect(close,&QPushButton::clicked, [=]{
//        windows->close();
//        close->setEnabled(false);
//        open->setEnabled(true);
//    });
}

Widget::~Widget()
{

}
