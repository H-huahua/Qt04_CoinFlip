#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    //构造参数 参数1 正常显示的图片路径 参数2 按下后现实的图片路径
    MyPushButton(QString normalImg, QString pressImag = "");
    //第二个参数默认值是空，因为第一个值一定要传，第二个值未必要传

    //成员属性 保存用户传入的默认显示路径以及  按下之后显示的图片路径
    QString normalImgPath;
    QString pressImgPath;

    //弹跳特效
    void zoom1();
    void zoom2();

    //重写按钮的按下 和 释放
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

};

#endif // MYPUSHBUTTON_H
