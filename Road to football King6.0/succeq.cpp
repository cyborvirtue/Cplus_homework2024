#include "succeq.h"
#include "ui_succeq.h"
#include<QSound>
#include<selectionmode.h>
static QSound nS2(":/succeq.wav");
succeq::succeq(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::succeq)
{
    ui->setupUi(this);
    nS2.setLoops(50);
    nS2.play();//设置声音的播放
}

succeq::~succeq()
{
    delete ui;
}

void succeq::on_pushButton_2_clicked()
{
    this->close();
    nS2.stop();
    SelectionMode*pi=new SelectionMode();
    pi->show();
}

void succeq::on_pushButton_clicked()
{
    this->close();
}
