#include "widget.h"
#include "ui_widget.h"
#include <QPainter>//画家类
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //按钮要写在构造函数中，不是写在绘图事件
    connect(ui->pushButton,&QPushButton::clicked,[=](){
         //如果手动调用绘图事件 用update进行更新
        posX +=20;
        update();
    });
}

void Widget::paintEvent(QPaintEvent *){
//    //实例化画家对象  this指定的是当前窗口中进行绘画
//    QPainter painter(this);

//    //设置笔的颜色
//    QPen pen(QColor(0,0,255));
//    //设置画笔宽度
//    pen.setWidth(3);
//    //设置画笔的风格：
//    pen.setStyle(Qt::DotLine);
//    //使用画笔
//    painter.setPen(pen);

//    //设置画刷
//    QBrush brush(Qt::green);
//    //设置画刷的风格
//    brush.setStyle(Qt::Dense6Pattern);
//    //让画家实用画刷：
//    painter.setBrush(brush);



//    //画直线
//    painter.drawLine(QPoint(0,0),QPoint(100,100));

//    //画圆
//    painter.drawEllipse(QPoint(100,100),100,50);

//    //画矩形
//    painter.drawRect(QRect(20,20,50,50));

//    //画文字
//    painter.drawText(QRect(10,200,100,50),"学习Qt");




    ///////////////////////////////////利用画家画资源和图片//////////////////////////
    QPainter painter(this);

    painter.drawPixmap(posX,100,QPixmap(":/Image/Luffy.png"));

}

Widget::~Widget()
{
    delete ui;
}

