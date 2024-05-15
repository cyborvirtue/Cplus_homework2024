#include "racemode.h"
#include "ui_racemode.h"
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
racemode::racemode(QWidget *parent) :
    QWidget(parent),
ui(new Ui::racemode)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
}
int racemode::ti =0;
int foods::nowtime=0;
int racemode::dec =0;
static QSound nS(":/new/prefix1/ zhanv.wav");
void racemode::paintEvent(QPaintEvent *event){
    //update()或程序第一次启动时自动执行，用于画图
    QPainter painter(this);

  speed=50;
    if(!blsRun){
        Initplayer();
        for(int i=0;i<5;i++){
        food11[i].Statufood1();
        food11[i].Initfood();
        nS.setLoops(50);
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
    painter.drawPixmap(20,20,500,700,QPixmap(":/WechatIMG586.png"));
    //画赛道
    painter.setPen(Qt::gray);//设置画笔颜色
    painter.setBrush(Qt::gray);//设置填充颜色
    painter.drawRect(55,35,2,650);
    painter.drawRect(475,35,2,650);
    painter.setPen(Qt::black);//设置画笔颜色
    //painter.draw
    for (int i=0;i<5;i++) {
        if(player.intersects(food11[i].singlefood)&&food11[i].live==1){
            QSound::play(":/bingo11.wav");
            food11[i].live=0;

            if(food11[i].kind==5){//创作者*5

                nScore*=2;
                 }
            else {
                nScore+=10;
            }


            }
        }
    painter.setPen(Qt::black);//设置画笔颜色
    painter.setBrush(Qt::white);//设置填充颜色
    painter.drawRect(540,220,120,10);
    painter.setPen(Qt::black);//设置画笔颜色
    painter.setBrush(Qt::black);//设置填充颜色

    painter.drawRect(540,220,tii/10,10);

    //得分显示
    QFont font2("Courier",15);
    painter.setFont(font2);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawText(600,300,scoreLabel);
    painter.drawText(600,330,QString::number(nScore));
    //画运动员
    for (int i=0;i<5;i++) {
        if(food11[i].kind==5){
            painter.drawPixmap(food11[i].singlefood,QPixmap(":/WechatIMG533.png"));
        }
        else {
             painter.drawPixmap(food11[i].singlefood,QPixmap(":/WechatIMG587.png"));    }
    }//画食物
    if(nScore>=2000){
        nS.stop();
        this->close();
        succezha*pi=new succezha();
         pi->show();

    }

    //画运动员
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
    if(tii==1500){
        nScore=0;
        tii=0;
    }

}
void racemode::Initplayer(){
    tii=0;
    prot=0;
//QSound::play(":/queen.wav");
    nDirection=2;//默认向下运动
    blsRun=true;
    scoreLabel="得分";
    nScore=0;
    QRect rect(70,550,40,50);//生成小方块的初始位置
    player=rect;//小方块赋值到
    QRect rect2(55,550,75,110);
    prote=rect2;
    timer=new QTimer(this);//设定计时器
    //timer->start(100000);//计时器时间是0.5s
    connect(timer,SIGNAL(timeout()),SLOT(player_update()));//信号连接槽，发出信号的是timer，信号是timeout，执行的槽是Snake_update
    //信号连接槽，发出信号的是timer，信号是timeout，执行的槽是Snake_update

}
void foods::Statufood1(){
    live=1;
    int x,y;
    x=rand()%5;//生成小于25的整数
    y=qrand()%14+1;//食物种类
    QRect rect(70+x*80,80,60,80);//食物小方块位置
    kind=y;
    singlefood=rect;
}

void foods::Initfood(){
    foodrun=true;
    food_timer=new QTimer(this);//设定计时器
    //food_timer->start(100000);//计时器时间是0.5s
    connect(food_timer,SIGNAL(timeout()),SLOT(food_update()));
}

void racemode::player_update(){//设置player的运动（碰壁返回）
manyfood();
tii++;
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
     prote.setRight(prote.right()-12);
        dec=3;
        player.setLeft(player.left()-12);
        player.setRight(player.right()-12);
        ti++;
        prot--;
        }
    if(nDirection==4){//right
       dec=4;
       prote.setLeft(prote.left()+8);
       prote.setRight(prote.right()+8);
        player.setLeft(player.left()+12);
        player.setRight(player.right()+12);
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

void foods::food_update(){

        if(kind==5){
             singlefood.setTop(singlefood.top()+40);
             singlefood.setBottom(singlefood.bottom()+40);
       }
         else{
         singlefood.setTop(singlefood.top()+20);
         singlefood.setBottom(singlefood.bottom()+20);
         nowtime++;}
         update();


}
void racemode::manyfood(){


    for (int i=0;i<5;i++) {
    if(food11[i].singlefood.top()>=650){
        food11[i].Statufood1();
    }
    if(food11[i].live==0){
        food11[i].Statufood1();
    }
    }

}
void racemode::on_pushButton_clicked()
{
    for (int i=0;i<5;i++) {
     int y;
     y=rand()%5;
    food11[i].food_timer->start(50+y*10);
   // food2[i].food_timer->start(speed);
    }

timer->start(50);

}
void racemode::teleport1()//实现瞬移功能
{
    nScore-=50;
    if(nDirection==3){  // 如果方向为向左
            prote.setLeft(prote.left()-40);  // 保护罩向左移动
            prote.setRight(prote.right()-40);
            dec=3;  // 设置玩家的朝向
            player.setLeft(player.left()-40);  // 玩家向左移动
            player.setRight(player.right()-40);
            ti++;  // 增加时间
            prot--;  // 减少保护罩时间
    }
       if(nDirection==4){  // 如果方向为向右
                    dec=4;  // 设置玩家的朝向
                    prote.setLeft(prote.left()+40);  // 保护罩向右移动
                    prote.setRight(prote.right()+40);
                    player.setLeft(player.left()+40);  // 玩家向右移动
                    player.setRight(player.right()+40);
                    prot--;  // 减少保护罩时间
                    ti++;  // 增加时间
                }
                if(player.left()<=70){  // 如果玩家碰到了左边界
                    nDirection=4;  // 玩家向右移动
                }
                if(player.left()>=390){  // 如果玩家碰到了右边界
                    nDirection=3;  // 玩家向左移动
                }
                update();
        }
void racemode::keyPressEvent(QKeyEvent *event){

    switch (event->key()) {

    case Qt::Key_Down: nDirection = 2; break; // 2代表向下
    case Qt::Key_Up: nDirection = 1; break; // 1代表向上
    case Qt::Key_Left: nDirection = 3; break; // 3代表向左
    case Qt::Key_Right: nDirection = 4; break; // 4代表向右
    case Qt::Key_Space:
           teleport1(); // 瞬移函数
    default:;
    }
}


void racemode::on_pushButton_4_clicked()
{
    nS.stop();
    this->close();
}

void racemode::on_pushButton_3_clicked()
{
    for (int i=0;i<5;i++) {

    food11[i].food_timer->stop();
   // food2[i].food_timer->start(speed);
    }

timer->stop();

    nS.stop();
    this->close();
    racemode*pi=new racemode();
    pi->show();
}

void racemode::on_pushButton_2_clicked()
{
    for (int i=0;i<5;i++) {

    food11[i].food_timer->stop();
   // food2[i].food_timer->start(speed);
    }

timer->stop();
}

racemode::~racemode()
{
    delete ui;
}
