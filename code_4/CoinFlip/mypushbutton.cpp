#include "mypushbutton.h"

#include <QDebug>
#include <QPropertyAnimation>

//MyPushButton::MyPushButton(QPushButton *parent)
//    : QWidget{parent}
//{

//}
//声明中有默认参数，实现中没有参数
MyPushButton::MyPushButton(QString normalImg, QString pressImag){
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImag;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret){
        qDebug()<<"图片加载失败";
        return;
    }

    //设置图片的固定大小
    this->setFixedSize(pix.width(),pix.height());

    //设置不规则图片样式：
    this->setStyleSheet("QPushButton{border:0px;}");//矩形变成正方形

    //设置图标
    this->setIcon(pix);

    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}



void MyPushButton::zoom1(){
    //创建动画对象：
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");

    //设置时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+20,this->width(),this->height()));

    //设置套弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();
}
void MyPushButton::zoom2(){
    //创建动画对象：
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");

    //设置时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+20,this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //设置套弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e){
    if(this->pressImgPath !=""){//传入的摁下图片不为空，说明需要有切换状态
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if(!ret){
            qDebug()<<"图片加载失败";
            return;
        }

        //设置图片的固定大小
        this->setFixedSize(pix.width(),pix.height());

        //设置不规则图片样式：
        this->setStyleSheet("QPushButton{border:0px;}");//矩形变成正方形

        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //让父类执行其他的内容
    return QPushButton::mousePressEvent(e);

}
void MyPushButton::mouseReleaseEvent(QMouseEvent *e){
    if(this->pressImgPath !=""){//传入的摁下图片不为空，说明需要有切换状态
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret){
            qDebug()<<"图片加载失败";
            return;
        }

        //设置图片的固定大小
        this->setFixedSize(pix.width(),pix.height());

        //设置不规则图片样式：
        this->setStyleSheet("QPushButton{border:0px;}");//矩形变成正方形

        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }

    //让父类执行其他的内容
    return QPushButton::mouseReleaseEvent(e);
}
