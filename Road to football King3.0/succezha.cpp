#include "succezha.h"
#include "ui_succezha.h"
#include"QSound"
#include"selectionmode.h"
static QSound  nS2(":/succzha.wav");
succezha::succezha(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::succezha)
{
    ui->setupUi(this);
    nS2.setLoops(50);
    nS2.play();
}

succezha::~succezha()
{
    delete ui;
}

void succezha::on_pushButton_2_clicked()
{
    this->close();
    nS2.stop();
    SelectionMode*pi=new SelectionMode();
    pi->show();
}

void succezha::on_pushButton_clicked()
{
    this->close();
}


