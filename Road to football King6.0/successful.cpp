#include "successful.h"
#include "ui_successful.h"
#include <QApplication>
#include <QMovie>
#include <QLabel>
#include"selectionmode.h"
#include<QSound>
static QSound  nS2(":/succeelizhi.wav");
successful::successful(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::successful)
{
    ui->setupUi(this);
    nS2.setLoops(50);
    nS2.play();

}

successful::~successful()
{
    delete ui;
}

void successful::on_pushButton_2_clicked()
{   nS2.stop();
    this->close();
    SelectionMode*pi=new SelectionMode();
    pi->show();
}

void successful::on_pushButton_clicked()
{
    this->close();
}
