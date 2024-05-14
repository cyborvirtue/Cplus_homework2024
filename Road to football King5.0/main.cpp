#include "twinkle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Twinkle w;
    w.show();

    return a.exec();
}
