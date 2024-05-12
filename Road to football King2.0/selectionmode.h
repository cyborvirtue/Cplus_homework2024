#ifndef SELECTIONMODE_H
#define SELECTIONMODE_H

#include <QWidget>
#include"maingame.h"
#include"grown.h"
#include"racemode.h"

namespace Ui {
class SelectionMode;
}

class SelectionMode : public QWidget
{
    Q_OBJECT

public:
    explicit SelectionMode(QWidget *parent = nullptr);
    ~SelectionMode();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::SelectionMode *ui;
};

#endif // SELECTIONMODE_H
