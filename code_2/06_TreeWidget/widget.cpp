#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //treeWidget树控件的使用
    //设置水平的头，用匿名对象
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");

    QTreeWidgetItem * liItem = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem * minItem = new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem * zhiItem = new QTreeWidgetItem(QStringList()<<"智力");
    //加载顶层节点
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(minItem);
    ui->treeWidget->addTopLevelItem(zhiItem);

    //追加子节点：

    QStringList heroL1;
    heroL1<<"z胖胖"<<"前排肉！！！防御力超级强，力量超级大！！吃吃吃，睡睡睡";
    QTreeWidgetItem * l1 = new QTreeWidgetItem(heroL1);
    liItem->addChild(l1);

    QStringList heroL2;
    heroL2<<"c混混"<<"超级混！！！混分力超级强，运气超级好！！从不带分，混吃等死";
    QTreeWidgetItem * l2 = new QTreeWidgetItem(heroL2);
    minItem->addChild(l2);

    QStringList heroL3;
    heroL3<<"g禽兽"<<"超级禽兽！！但是属于智力型选手！！！有过目不忘的本领！！！";
    QTreeWidgetItem * l3 = new QTreeWidgetItem(heroL3);
    zhiItem->addChild(l3);
}

Widget::~Widget()
{
    delete ui;
}

