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

    QMap<int, QVector< QVector<int> > >mData;
    //键值对 一个数字对应一个二维数组，即实现第一关的二维数组是什么，第二关的二维数组是什么



signals:

public slots:
};

#endif // DATACONFIG_H
