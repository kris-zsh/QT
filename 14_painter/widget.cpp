#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPoint>
#include <QTimer>
#include <QPixmap>
#include <QImage>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QTimer* timer = new QTimer(this);
//    timer->setInterval(500);

//    connect(timer, &QTimer::timeout,[=]{
//       posX += 20;
//       this->update();
//    });
//    timer->start();


//    QPixmap map(100,100);
//    QPainter painter(&map);
//    map.fill(Qt::cyan);
//    painter.drawEllipse(QPoint(100,100),50,50);
//    map.save(R"(D:\BaiduNetdiskDownload\Qt-学习\QT资料\day3资料\Code\04_QtPaintDevice\Image\1.png)");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
//    QPainter painter(this);


//    painter.setBrush(Qt::cyan);
//    painter.setPen(Qt::darkBlue);

//    painter.drawLine(QPoint(0,0), QPoint(100,100));
//    painter.drawEllipse(QPoint(100,100),30,30);
//    painter.drawRect(QRect(QPoint(200,400), QPoint(600,800)));

//    painter.drawText(QRect(QPoint(600, 300), QPoint(700,400)), "青春没有售价，硬座直达拉萨");

//    /////////////////////////高级设置
//    QPainter painter(this);

//    painter.drawEllipse(QPoint(100,100),200,200);
//    painter.setRenderHint(QPainter::HighQualityAntialiasing);
//    painter.drawEllipse(QPoint(200,200),200,200);

//    painter.drawRect(100,200,100,100);

//    painter.save();
//    painter.translate(100,100);
//    painter.drawRect(100,200,100,100);

//    painter.restore();
//    painter.translate(100,100);
//    painter.drawRect(100,200,100,100);


//    ///////////手动绘图
//    ///
//    QPainter painter(this);
//    if(posX >= this->width())
//        posX = 0;
//    painter.drawImage(50,50);
}
