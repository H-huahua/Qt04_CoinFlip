#include "mainwindow.h"
#include<QMenuBar>
#include<QToolBar>
#include<QDebug>
#include<QPushButton>
#include<QLabel>
#include<QStatusBar>
#include<QDockWidget>
#include<QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    resize(600,400);

    //菜单栏 最多只有一个
    //菜单栏创建：
    QMenuBar *bar =  menuBar();//源码已经把这个函数创建在了对象树上
    //将菜单栏放入到窗口中：
    setMenuBar(bar);
    //此时空栏已经放进去，但是没有东西，所以不显示

    //创建菜单：
    QMenu * fileMenu = bar->addMenu("文件");
    QMenu * editMenu = bar->addMenu("编辑");

    //创建菜单项：
    QAction *newAction = fileMenu->addAction("新建");
    //添加分隔线
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("打开");


    //工具栏可以有多个：
    QToolBar *toolBar = new QToolBar(this);//创建在对象树
    addToolBar(Qt::LeftToolBarArea, toolBar);
    //后期设置 只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea |Qt::RightToolBarArea);

    //设置浮动：
    toolBar->setFloatable(false);

    //设置移动（总开关）
    toolBar->setMovable(false);

    //工具栏中可以设置内容
    toolBar->addAction(newAction);
    //新建分割线
    toolBar->addSeparator();
    toolBar->addAction(openAction);
    //工具栏中添加控件：
    QPushButton * btn = new QPushButton("aa",this);
    toolBar->addWidget(btn);

    //状态栏 最多有一个
    QStatusBar * stBar = statusBar();
    //设置到窗口中
    setStatusBar(stBar);
    //放标签控件
    QLabel * label = new QLabel("提示信息",this);
    stBar->addWidget(label);

    QLabel * label2 = new QLabel("右侧提示信息",this);
    stBar->addPermanentWidget(label2);


   //铆接部件（浮动窗口）
    QDockWidget * dockWidget = new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);

    //设置后期的停靠，只允许上下
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

   //设置中心部件 只能一个
    QTextEdit * edit = new QTextEdit(this);
    setCentralWidget(edit);


}

MainWindow::~MainWindow()
{
}

