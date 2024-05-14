#include"grown.h"
#include "ui_grown.h"
#include"selectionmode.h"
#include<qrect.h>
#include<qtimer.h>
#include<QKeyEvent>
#include<QDebug>
#include<QFont>
#include<QPixmap>
#include <QIcon>
#include <QPalette>
#include <QPixmap>
#include <QMessageBox>
#include <QRect>
#include<QMovie>
#include<QSound>
#include <QMediaPlayer>
#include <QMediaPlaylist>
int grown::ti =0;
int foodq::nowtime=0;
int grown::dec =0;
static QSound nS(":/queen.wav");

grown::grown(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::grown)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
}
void grown::paintEvent(QPaintEvent *event){
    //update()或程序第一次启动时自动执行，用于画图
    QPainter painter(this);

  speed=50;
    if(!blsRun){
        Initplayer();
        for(int i=0;i<5;i++){
        food11[i].Statufood1();
        food11[i].Initfood();
        nS.setLoops(5000);
        nS.play();
        }
    }

        int sta=1;
//QMovie *movie = new QMovie("/Users/Biao/Desktop/x.gif");
    //外墙
    painter.setPen(Qt::black);//设置画笔颜色
    painter.setBrush(Qt::black);//设置填充颜色
    painter.drawRect(15,15,510,710); //画矩形，相对于窗体的起点坐标（15，15），大小260*260
    //内墙
    painter.setPen(Qt::black);//设置画笔颜色
    painter.setBrush(Qt::white);//设置填充颜色
    painter.drawRect(20,20,500,700); //画矩形，相对于窗体的起点坐标（20，20），大小250*250
    painter.drawPixmap(20,20,500,700,QPixmap(":/WechatIMG552.jpeg"));
    //画赛道
    painter.setPen(Qt::black);//设置画笔颜色
    painter.setBrush(Qt::black);//设置填充颜色
    painter.drawRect(55,35,2,650);
    painter.drawRect(475,35,2,650);
    painter.setPen(Qt::black);//设置画笔颜色
    //painter.draw
    for (int i=0;i<5;i++) {
        if(player.intersects(food11[i].singlefood)&&food11[i].live==1){

            food11[i].live=0;
            if(food11[i].kind==1){//健身+50

                QSound::play(":/bingo11.wav");
                nScore+=50;
                 }
            if(food11[i].kind==2||food11[i].kind==3){//战术训练+30

                QSound::play(":/bingo11.wav");nScore+=30;
                 }
            if(food11[i].kind==4){//实战比赛*2

                QSound::play(":/bingo11.wav"); nScore*=2;
                 }
            if(food11[i].kind==5){//创作者*5

                QSound::play(":/bingo11.wav"); prot=200;
                 }
            if(food11[i].kind==6||food11[i].kind==7||food11[i].kind==8){///2
                if(prot<=0){
                    QSound::play(":/bingo.wav");}
                    nScore/=2;

                 }
            if(food11[i].kind==9||food11[i].kind==10||food11[i].kind==11){//-50
                if(prot<=0){
                    QSound::play(":/bingo.wav");
                    nScore-=50;}

            }
            if(food11[i].kind==12||food11[i].kind==13||food11[i].kind==14){//-30
                if(prot<=0) {QSound::play(":/bingo.wav");nScore-=30;}

            }
        }

    }

    //得分显示
    QFont font2("Courier",15);
    painter.setFont(font2);
    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawText(600,300,scoreLabel);
    painter.drawText(600,330,QString::number(nScore));
    //画人:/WechatIMG502.jpeg
    for (int i=0;i<5;i++) {
        if(food11[i].kind==1){//健身+50
             painter.drawPixmap(food11[i].singlefood,QPixmap(":/WechatIMG553.png"));
        }
        if(food11[i].kind==2||food11[i].kind==3){//战术训练+30
             painter.drawPixmap(food11[i].singlefood,QPixmap(":/WechatIMG554.png"));
        }
        if(food11[i].kind==4){//实战比赛x2
             painter.drawPixmap(food11[i].singlefood,QPixmap(":/WechatIMG555.png"));
        }
        if(food11[i].kind==5){//创作者*5

             painter.drawPixmap(food11[i].singlefood,QPixmap(":/WechatIMG560.png"));
        }
        if(food11[i].kind==6||food11[i].kind==7||food11[i].kind==8){//酒精/2
             painter.drawPixmap(food11[i].singlefood,QPixmap(":/WechatIMG561.png"));
        }
        if(food11[i].kind==9||food11[i].kind==10||food11[i].kind==11){//沉迷游戏-50
             painter.drawPixmap(food11[i].singlefood,QPixmap(":/WechatIMG562.png"));
        }
        if(food11[i].kind==12||food11[i].kind==13||food11[i].kind==14){//沉迷夜店-30
             painter.drawPixmap(food11[i].singlefood,QPixmap(":/WechatIMG563.png"));
        }
    }//画食物
    if(nScore>=5000){
        nS.stop();
        this->close();
        succeq*pi=new succeq();
         pi->show();

    }
    //画人
    if(dec==3){
   if(ti%4==1||ti%4==2){
    painter.drawPixmap(player,QPixmap(":/nv1.png"));}
    else {
        painter.drawPixmap(player,QPixmap(":/nv2.png"));
    }}
    else {
        if(ti%4==1||ti%4==2){
         painter.drawPixmap(player,QPixmap(":/nv4.png"));}
         else {
             painter.drawPixmap(player,QPixmap(":/nv3.png"));
         }
    }
    if(prot>0){
    painter.drawPixmap(prote,QPixmap(":/9d5406dae9c53a85394f9602bb120391.png"));
    }

}
void grown::Initplayer(){
    prot=0;


//QSound::play(":/queen.wav");
    nDirection=2;//默认向下运动
    blsRun=true;
    scoreLabel="得分";
    nScore=0;
    QRect rect(70,600,40,50);//生成小方块的初始位置
    player=rect;//小方块赋值到运动员
    QRect rect2(55,550,75,110);
    prote=rect2;
    timer=new QTimer(this);//设定计时器
    //timer->start(100000);//计时器时间是0.5s
    connect(timer,SIGNAL(timeout()),SLOT(player_update()));//信号连接槽，发出信号的是timer，信号是timeout，执行的槽是Snake_update
    //信号连接槽，发出信号的是timer，信号是timeout，执行的槽是Snake_update

}
void foodq::Statufood1(){
    live=1;
    int x,y;
    x=rand()%5;//生成小于25的整数
    y=qrand()%14+1;//食物种类
    QRect rect(70+x*80,80,60,80);//食物小方块位置
    kind=y;
    singlefood=rect;
}

void foodq::Initfood(){
    foodrun=true;
    food_timer=new QTimer(this);//设定计时器
    //food_timer->start(100000);//计时器时间是0.5s(!)
    connect(food_timer,SIGNAL(timeout()),SLOT(food_update()));
}
void grown::player_update(){
manyfood();
if(nDirection==8){
    nDirection=7;

    nScore+=1000;
}
if(nDirection==2){
    prote.setLeft(prote.left());
    prote.setRight(prote.right());

       player.setLeft(player.left());
       player.setRight(player.right());
prot--;
       }
 if(nDirection==3){//left
     prote.setLeft(prote.left()-8);
     prote.setRight(prote.right()-8);
        dec=3;
        player.setLeft(player.left()-8);
        player.setRight(player.right()-8);
        ti++;
        prot--;
        }
    if(nDirection==4){//right
       dec=4;
       prote.setLeft(prote.left()+8);
       prote.setRight(prote.right()+8);
        player.setLeft(player.left()+8);
        player.setRight(player.right()+8);
        prot--;
     ti++;
    }
    if(player.left()<=70){
        nDirection=4;
    }//碰壁返回
    if(player.left()>=390){
        nDirection=3;
    }

    update();
}

void foodq::food_update(){

        if(kind==5){
             singlefood.setTop(singlefood.top()+30);
             singlefood.setBottom(singlefood.bottom()+30);
       }
         else{
         singlefood.setTop(singlefood.top()+15);
         singlefood.setBottom(singlefood.bottom()+15);
         nowtime++;}
         update();


}
void grown::manyfood(){

    for (int i=0;i<5;i++) {
    if(food11[i].singlefood.top()==650){
        food11[i].Statufood1();
    }
    if(food11[i].live==0){
        food11[i].Statufood1();
    }
    }
}
void grown::on_pushButton_clicked()
{
    for (int i=0;i<5;i++) {
     int y;
     y=rand()%5;
    food11[i].food_timer->start(50+y*10);
     //food11[i].food_timer->start(speed);
    }

timer->start(50);

}
void grown::keyPressEvent(QKeyEvent *event){

    switch (event->key()) {
    case Qt::Key_Down:nDirection=2;   //3代表左
        break;
    case Qt::Key_Left:nDirection=3;   //3代表左
        break;
    case Qt::Key_Right:nDirection=4;   //4代表右
        break;
    case Qt::Key_S:nDirection=8;
    default:;
    }
}

grown::~grown()
{
    delete ui;
}

void grown::on_pushButton_4_clicked()
{
    nS.stop();
    this->close();
}

void grown::on_pushButton_3_clicked()
{
    for (int i=0;i<5;i++) {

    food11[i].food_timer->stop();
   // food2[i].food_timer->start(speed);
    }

timer->stop();

    nS.stop();
    this->close();
    SelectionMode*pi=new SelectionMode();
    pi->show();
}

void grown::on_pushButton_2_clicked()
{
    for (int i=0;i<5;i++) {

    food11[i].food_timer->stop();
   // food2[i].food_timer->start(speed);
    }

timer->stop();
}



void grown::on_pushButton_pressed()
{

}
