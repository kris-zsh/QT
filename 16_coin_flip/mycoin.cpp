#include "mycoin.h"
#include <QPixmap>

MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
{

}

MyCoin::MyCoin(QString image)
{
    image_ = image;

    QPixmap map(image);
    this->setFixedSize(map.width(), map.height());
    this->setStyleSheet("QPushButton:{border:0px;}");
    this->setIcon(map);
    this->setIconSize(QSize(map.width(), map.height()));
}
