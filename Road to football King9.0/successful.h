#ifndef SUCCESSFUL_H
#define SUCCESSFUL_H

#include <QWidget>

namespace Ui {
class successful;
}

class successful : public QWidget
{
    Q_OBJECT

public:
    explicit successful(QWidget *parent = nullptr);
    ~successful();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::successful *ui;
};

#endif // SUCCESSFUL_H
