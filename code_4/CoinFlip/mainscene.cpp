#include "mainscene.h"
#include "ui_mainscene.h"
#include "mypushbutton.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QSound>//多媒体模块下的音效
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //配置主场景

    //设置固定大小

    setFixedSize(320,588);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("翻金币的主场景");

    //退出按钮
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });
    //准备开始按钮的音效
    QSound * startSound = new QSound(":/res/TapButtonSound.wav",this);

    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);

    //实例化选择关卡
    chooseScene = new ChooseLevelScene;

    //监听选择关卡的返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseScenBack,this,[=](){

        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();//将选择关卡场景隐藏
        this->show();//重新显示主场景
    });

    connect(startBtn,&MyPushButton::clicked,[=](){
        qDebug()<<"点击了开始";
        //播放开始音效资源
        startSound->play();

        startBtn->zoom1();
        startBtn->zoom2();

        //添加延迟进入到选择关卡之中
        //延迟0.5秒，用this来触发另一个函数，用lambda表达式
        QTimer::singleShot(500,this,[=](){
            //设置chooseScene场景的位置
            chooseScene->setGeometry(this->geometry());

            //自身隐藏
            this->hide();
            //显示选择关卡
            chooseScene->show();


        });


    });


}

void MainScene::paintEvent(QPaintEvent *event){
    //创建画家 指定绘画设备
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/res/PlayLevelSceneBg.png");
    //使用拉伸方法，拉伸成屏幕大小尺寸的图片！
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //背景图上的图标
    pix.load(":/res/Title.png");

    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);
}

MainScene::~MainScene()
{
    delete ui;
}

