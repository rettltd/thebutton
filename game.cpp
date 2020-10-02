#include "game.h"
#include <math.h>
#include <cstdlib>
#include <QDebug>
#include <QRandomGenerator>
#define qrand() QRandomGenerator::system()->generate()

int Game::color1;
int Game::color2;
int Game::c1;
int Game::c2;
QColor Game::buttoncolor;
//color array for button and background
const QColor Game::col[16]=
{
    QColor(0xff4f0014), QColor(0xff00ff00), QColor(0xff122faa), QColor(0xffffffff), //Red Lim Blu Wht
    QColor(0xffffff00), QColor(0xff000000), QColor(0xfffcdd76), QColor(0xffff1493), //Yel Blk Snd Pnk
    QColor(0xff442d25), QColor(0xffffb28b), QColor(0xff4b0082), QColor(0xff876c99), //Cof Sky Ind Gry
    QColor(0xff008000), QColor(0xffff4f00), QColor(0xff002f55), QColor(0xffc10020)  //Gre Orn Dbl Prp
};
//corresponding color names
const QString Game::cs[16]=
{
    "Deep red", "Lime", "BSOD", "White",
    "Yellow", "Black", "Sand", "Pink",
    "Coffee", "Yellow-pink", "Indigo", "Light Purp",
    "Green", "Orange", "Deep blue", "Red"
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
    //check if colors match after press
    if((color1 == c1 && color2 == c2) || (color1 == c2 && color2 == c1))
    {
        generate();
        return 1;
    }
    else return 0;
}

void Game::update(widget &W)
{
    currentTick++;
    //current colors
    if(currentTick >= tick)
    {
        int t = qrand() % 2;
        c1 = color1 * t + color2 * (1 - t);
        c2 = color2 * t + color1 * (1 - t);
        tick = qrand() % 7 + 1;
        currentTick = 0;
    }
    else //16 - nomb of colors
    {
        c1 = qrand() % 16;
        c2 = qrand() % 16;
    }
    W.setColor(c2);
}

void Game::generate()
{
    tick = qrand() % 7+ 1;// pseudorandom, necessary color combimation guaranteed to appear
    //generate random colors
    color1 = qrand() % 16;
    color2 = qrand() % 16;
}
