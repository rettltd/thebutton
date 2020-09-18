#include "game.h"
#include <math.h>
#include <cstdlib>
#include <QDebug>
int Game::color1;
int Game::color2;
int Game::c1;
int Game::c2;
const QColor Game::col[16]={
    QColor(0xf0ff0000), QColor(0xf000ff00), QColor(0xf00000ff), QColor(0xf0ffffff), //Red Grn Blu Wht
    QColor(0xf0ffff00), QColor(0xf0000000), QColor(0xf000ffff), QColor(0xf0ff00ff), //Yel Blk Lbl Pnk
    QColor(0xf000ff7f), QColor(0xf0007fff), QColor(0xf0007f7f), QColor(0xf07f7f7f), //USD Sky Wav Gry
    QColor(0xf07f0000), QColor(0xf0ff7f00), QColor(0xf000007f), QColor(0xf07f007f) //Bld Orn Dbl Prp
};
const QString Game::cs[16]={
    "Red", "Green", "Blue", "White",
    "Yellow", "Black", "Light blue", "Pink",
    "Light green", "Sky", "Wave", "Gray",
    "Blood", "Orange", "Dark blue", "Purple"
};

Game::Game()
{
    currentTick = 0;
    tick = 0;
    color1 = qrand() % 16;
    color2 = qrand() % 16;
}

bool Game::check()
{
    //qDebug() << "color1  = " << color1 << "color2 = " << color2 << "c1 = "<<  c1 << "c2 = " << c2 << "tick = " << tick;
    if((color1 == c1 && color2 == c2) || (color1 == c2 && color2 == c1)){
        generate();
        return 1;
    }
    else return 0;
}

void Game::update(widget &W)
{
    currentTick++;
    //current colors
    if(currentTick >= tick){
        int t = qrand() % 2;
        c1 = color1 * t + color2 * (1 - t);
        c2 = color2 * t + color1 * (1 - t);
        tick = qrand() % 7 + 1;
        currentTick = 0;
    }
    else{//16 - nomb of colors
        c1 = qrand() % 16;
        c2 = qrand() % 16;
    }
    //W.RoundButton.setColor(c1);
    W.setColor(c2);
}

void Game::generate()
{
    tick = qrand() % 7+ 1;// через сколько апдейтов будет гарантировано правильная комбинация
    color1 = qrand() % 16;
    color2 = qrand() % 16;
}
