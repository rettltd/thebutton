#ifndef RETT_H
#define RETT_H

#include <QMainWindow>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QApplication>
#include "mainwidget.h"

class rett : public QMainWindow
{
    Q_OBJECT

public:
    MainWidget m;
    QTimer timew;
    QMediaPlayer musisch;
    QMediaPlaylist pllst;

    rett(QWidget *parent = nullptr);
    ~rett();

public slots:
    void onTimeout();
    void musikAFK();
};
#endif // RETT_H
