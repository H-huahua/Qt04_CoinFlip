#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->actionnew->setIcon(QIcon("D:/Qt/qtStudy/Doc/Image/Luffy.png"));

    //使用Qt添加Qt资源":+前缀名+文件名"
    ui->actionnew->setIcon(QIcon(":/Image/Luffy.png"));
    ui->actionopen->setIcon(QIcon(":/Image/LuffyQ.png"));
}

MainWindow::~MainWindow()
{
    delete ui;

}

