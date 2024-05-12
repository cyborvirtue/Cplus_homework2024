#ifndef TWINKLE_H
#define TWINKLE_H

#include <QMainWindow>
#include"maingame.h"
#include"selectionmode.h"
#include<QSound>
namespace Ui {
class Twinkle;
}

class Twinkle : public QMainWindow
{
    Q_OBJECT

public:
    explicit Twinkle(QWidget *parent = nullptr);
    ~Twinkle();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Twinkle *ui;
};

#endif // TWINKLE_H
