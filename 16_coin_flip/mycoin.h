#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    static bool is_active;
    explicit MyCoin(QWidget *parent = 0);
    MyCoin(QString image, int isGold);
    void reverse_coin();
    bool isGold();
    void mousePressEvent(QMouseEvent *e);
private:
    QTimer* timer1;
    QTimer* timer2;

    int cur = 0;
    QString image_;
    int is_gold_ = false;

signals:

public slots:
};

#endif // MYCOIN_H
