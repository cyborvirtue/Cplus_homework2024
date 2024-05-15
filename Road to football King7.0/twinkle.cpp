#include "twinkle.h"
#include "ui_twinkle.h"
#include <QIcon>
#include <QPalette>
#include <QPixmap>
#include <QMessageBox>
#include <QRect>
#include<QSound>
Twinkle::Twinkle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Twinkle)
{
    ui->setupUi(this);

}

Twinkle::~Twinkle()
{
    delete ui;
}

void Twinkle::on_pushButton_clicked()
{
this->close();
    SelectionMode*pic=new SelectionMode();
    pic->show();
}



void Twinkle::on_pushButton_2_clicked()
{
   this->close();
    delete ui;
}
