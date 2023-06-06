#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置单选按钮，男默认选中：
    ui->rBtnMan->setChecked(true);
    //选中女之后，打印信息
    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
        qDebug()<<"选中了女！";

    //多选按钮 2是选中 0是未选中
        connect(ui->cBtn,&QCheckBox::stateChanged,[=](int state){
            qDebug()<<state;
        });
    });


//    //利用QListWidget写诗
//    QListWidgetItem * item = new QListWidgetItem("床前明月光");
//    //将一行诗放入到ListWidget控件中
//    ui->listWidget->addItem(item);
//    //水平居中
//    item->setTextAlignment(Qt::AlignHCenter);

    //QStringList  QList<QString>
    QStringList list;
    list<<"锄禾日当午" <<"汗滴禾下土"<<"谁知盘中餐"<<"粒粒皆辛苦";
    ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}

