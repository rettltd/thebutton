#include "rett.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(time(NULL));

    QFile file(":/style.qss");
    file.open(QIODevice::ReadOnly);
    QString line = file.readAll();
    a.setStyleSheet(line);
    file.close();

    rett w;
    w.show();
    a.connect(&a, &QApplication::applicationStateChanged, &w, &rett::musikAFK);
    return a.exec();
}
