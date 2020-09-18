#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QSoundEffect>

#include "widget.h"
#include "colorfulscore.h"
#include "wondertext.h"
#include "game.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:

    QSoundEffect ok_sound;
    QSoundEffect misclick_sound;
    QSoundEffect lose_sound;
    //QSoundEffect start_sound;

    QGridLayout *glay;
    widget widg;
    ColorfulScore score1;
    WonderText text1;
    WonderText text2;
    Game game;

    int hp=3;
    QColor hpC[4]={QColor(0xffc51b1b), QColor(Qt::red), QColor(Qt::yellow), QColor(Qt::green)};
    bool isGame;
    bool audioOff=0;
    explicit MainWidget(QWidget *parent = nullptr);
    void onTimeout();
private:
    int timer;
    int speed=1000;
signals:

public slots:
    void onPrssed();
    void audioNull();
};

#endif // MAINWIDGET_H
