#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTime>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QWidget *parent = nullptr);
    //参数代表传递的是  金币路径  还是  银币路径
    MyCoin(QString btnImg);

    //金币的属性
    int posX;//x坐标位置
    int posY;//y坐标位置
    bool flag;//正反标识


    //改变标志的方法
    void changeFlag();
    QTimer * timer1;//正面翻反面定时器
    QTimer * timer2;//反面翻正面定时器
    int min = 1;
    int max = 8;
    //执行动画的标志
    bool isAnimation = false;

    //重写 按下 和 释放
    void mousePressEvent(QMouseEvent *e);

signals:

};

#endif // MYCOIN_H
