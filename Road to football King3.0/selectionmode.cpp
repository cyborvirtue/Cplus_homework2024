#include "selectionmode.h"
#include "ui_selectionmode.h"
#include"twinkle.h"
SelectionMode::SelectionMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectionMode)
{
    ui->setupUi(this);
}

SelectionMode::~SelectionMode()
{
    delete ui;
}

void SelectionMode::on_pushButton_2_clicked()
{

}

void SelectionMode::on_pushButton_clicked()//grown模式
{
    this->close();
       grown*pi=new grown();
        pi->show();
}

void SelectionMode::on_pushButton_3_clicked()
{
    this->close();
      racemode*pi=new racemode();
      pi->show();
}

void SelectionMode::on_pushButton_5_clicked()
{
    this->close();
    Twinkle*pi=new Twinkle();
    pi->show();
}


void SelectionMode::on_pushButton_4_clicked()
{
    this->close();
}
