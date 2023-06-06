#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //TableWidget控件
    //设置列数为3列
    ui->tableWidget->setColumnCount(3);

    //设置水平的表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");

    //设置行数
    ui->tableWidget->setRowCount(5);

    //设置正文
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("z胖胖"));
    QStringList nameList;
    nameList<<"z胖胖"<<"c混混"<<"g禽兽"<<"s苟"<<"d苟";
    QList<QString> sexList;
    sexList<<"男"<<"男"<<"男"<<"男"<<"男";

    for(int i ;i<5 ;i++){
        int col = 0;
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(sexList.at(i)));
        //int转QString

        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(i+18)));
    }

}

Widget::~Widget()
{
    delete ui;
}

