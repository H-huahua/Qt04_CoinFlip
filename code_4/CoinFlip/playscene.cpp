#include "playscene.h"

#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "mycoin.h"
#include "dataconfig.h"

//PlayScene::PlayScene(QWidget *parent)
//    : QMainWindow{parent}
//{

//}


PlayScene::PlayScene(int levelNum){
    QString str = QString("进入了第%1关").arg(levelNum);
    qDebug()<<str;
    this->levelIndex = levelNum;

    //初始化游戏场景：
    //设置固定大小：
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币游戏场景");
    //创建菜单栏
    QMenuBar * bar = menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");
    //创建退出  菜单项
    QAction * quitAction = startMenu->addAction("退出");
    //点击退出
    connect(quitAction,&QAction::triggered,[=](){
        this->close();


    });
    //返回按钮
    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(), this->height() - backBtn->height());

    //点击返回
    connect(backBtn,&MyPushButton::clicked,[=](){
        qDebug()<< "游戏场景中点, 击了返回按钮";
        //告诉主场景我反悔了，主场景监听ChooseLevelScene的返回按钮
        //做一个延时返回
        QTimer::singleShot(500,this,[=](){
            emit this->chooseSceneBack();
        });

    });

    //显示当前关卡数
    QLabel * label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str1 = QString("Level:%1").arg(this->levelIndex);

    //将字体设置到标签控制中
    label->setFont(font);
    label->setText(str1);
    label->setGeometry(30,this->height()-50,120,50);


    dataConfig config;
    //初始化每个关卡的二维数组
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    //显示金币的背景图案
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            //绘制背景图案
            QPixmap pix = QPixmap(":/res/BoardNode.png");
            QLabel * label = new QLabel;
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57+i*50,200+j*50);

            //创建金币和银币
            if(this->gameArray[i][j]==1){
                //显示金币
                str = ":/res/Coin0001.png";
            }
            else{
                //显示银币
                str = ":/res/Coin0008.png";
            }

            MyCoin * coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59+i*50,204+j*50);

            //给金币属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];//1正面  0反面

            //点击金币，进行翻转
            connect(coin,&MyCoin::clicked,[=](){
                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j] == 0?1:0;
            });


        }

    }

}


void PlayScene::paintEvent(QPaintEvent *event){
    //创建背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    //加载背景，左边放在中间，长宽为原有的，图形为pix
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);
}
