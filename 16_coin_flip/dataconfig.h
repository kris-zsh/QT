#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
#include <QMap>
#include <QVector>

class dataConfig : public QObject
{
    Q_OBJECT
public:
    explicit dataConfig(QObject *parent = 0);

public:

    static QMap<int, QVector< QVector<int> > >mData;



signals:

public slots:
};

#endif // DATACONFIG_H
