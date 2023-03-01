#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>
#include <QString>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = 0);
    MyCoin(QString image);
private:
    QString image_;
signals:

public slots:
};

#endif // MYCOIN_H
