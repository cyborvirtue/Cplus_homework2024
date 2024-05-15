#ifndef RACEMODE_H
#define RACEMODE_H
#include <QWidget>
#include <QMainWindow>
#include<qpainter.h>
#include<QVector>
#include<qstring.h>
#include<food.h>
#include <QPainter>
#include <QKeyEvent>
#include <qtimer.h>
#include <vector>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include<QSound>
#include"succezha.h"
namespace Ui {
class racemode;
}

class foods: public QWidget
{
Q_OBJECT



public:
    QRect singlefood;//食物小方
     void Initfood();//连接计时器
    bool foodrun;
   QTimer *food_timer;//食物计时器
   void Statufood1();//初始化食物位置
    static int nowtime;
     int kind;//食物种类
     int live;//是否碰撞

private slots:
    void food_update();//食物槽
};//3
class racemode : public QWidget
{
    Q_OBJECT
public:
    explicit racemode(QWidget *parent = 0);
        ~racemode();
    //////////////////////////////////////////////////////////////
        void paintEvent(QPaintEvent *event);//绘制背景
        void Initplayer();//初始化运动员
        static int ti;//时间（gif用
       static int dec;//gif方向
        foods food11[5];//多个食物

        QRect prote;
        QRect player;//运动员
        void keyPressEvent(QKeyEvent *key);//定义键盘事件
        int nDirection;//移动的方向
       int tii;
        int speed=25;//移动速度
        float sta=0.1;
        int prot;//护盾
        ///////////////////////////////////////////////////////
        QTimer *timer;//定时器

        bool blsRun;//是否开始
        bool blsOver;//是否结束
        int nScore;//分数
        QString scoreLabel;//分数框

        void manyfood();//多个食物
        void teleport1();

    private slots:
        void player_update();//定义槽函数

        void on_pushButton_clicked();



        void on_pushButton_4_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_2_clicked();

private:
    Ui::racemode *ui;
};


#endif // RACEMODE_H
