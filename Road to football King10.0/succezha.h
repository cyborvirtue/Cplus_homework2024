#ifndef SUCCEZHA_H
#define SUCCEZHA_H

#include <QWidget>

namespace Ui {
class succezha;
}

class succezha : public QWidget
{
    Q_OBJECT

public:
    explicit succezha(QWidget *parent = nullptr);
    ~succezha();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::succezha *ui;
};

#endif // SUCCEZHA_H
