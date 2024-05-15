#ifndef SUCCEQ_H
#define SUCCEQ_H

#include <QWidget>

namespace Ui {
class succeq;
}

class succeq : public QWidget
{
    Q_OBJECT

public:
    explicit succeq(QWidget *parent = nullptr);
    ~succeq();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::succeq *ui;
};

#endif // SUCCEQ_H
