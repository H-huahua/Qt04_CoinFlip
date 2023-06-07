#include "widget.h"
#include "ui_widget.h"

#include <QTimer>//定时器的类
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器：
    id1 = startTimer(1000);//参数1 间隔 单位是毫秒
    id2 = startTimer(2000);

    //定时器第二种方式：
    //创建一个类，通过类来实例化一个对象
    QTimer * timer = new QTimer(this);
    //启动定时器
    timer->start(500);
    connect(timer,&QTimer::timeout,[=](){
        static int num3 = 1;
        //label4每隔0.5秒钟加1
        ui->label_4->setText(QString::number(num3++));
    });

    //点击暂停按钮 实现定时器暂停
    connect(ui->btn,&QPushButton::clicked,[=](){
        timer->stop();
    });

}

void Widget::timerEvent(QTimerEvent * ev){
    if(ev->timerId() == id1){
        static int num = 1;
        //label2每隔1秒钟加1
        ui->label_2->setText(QString::number(num++));
    }
    if(ev->timerId() == id2){
        //label3每隔2秒钟加1
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }

}

Widget::~Widget()
{
    delete ui;
}

