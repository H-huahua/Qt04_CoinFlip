#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击选取文件按钮，弹出文件对话框
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\Huahua\\Desktop");
        //将路径放到lineEdit中
        ui->lineEdit->setText(path);

        //编码格式类
        QTextCodec * codec = QTextCodec::codecForName("gbk");

        //读取内容  放到texeEdit中
        //QFile默认支持的格式的utf-8
        QFile file(path);//参数就是读取文件的路径
        //设置打开方式
        file.open(QIODevice::ReadOnly);
        //QByteArray array = file.readAll();//读取到的数据保存在参数array中

        QByteArray array;
        while(!file.atEnd()){
            array += file.readLine();
        }
        //将读取到的数据放入到textEdit中
        ui->textEdit->setText(array);
        //ui->textEdit->setText(codec->toUnicode(array));

        //对文件对象进行关闭
        file.close();


        //进行写文件
//        file.open(QIODevice::Append);//用追加的方式进行写入
//        file.write("啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊");
//        file.close();

        //QFileInf文件的构造：
        QFileInfo info(path);
        qDebug()<<"大小："<<info.size()<<"后缀名："<<info.suffix()<<"文件名称："<<info.fileName()<<"文件路径："<<info.filePath();
        qDebug()<<"创建日期："<<info.created().toString("yyyy/MM/dd hh:mm:ss");
        qDebug()<<"最后修改时间："<<

    });
}

Widget::~Widget()
{
    delete ui;
}


