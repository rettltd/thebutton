#ifndef CIRCLEOOP_H
#define CIRCLEOOP_H
#include <QPainter>
#include <QPainterPath>
#include <QBrush>
#include <QColor>
#include <QFont>
#include <math.h>
//#include "game.h"
class Circleoop
{
public:
    int xc=0;
    int yc=0;
    int ccolor;
    int radius=0;
    QString text="";
    QFont fonT;

    Circleoop();
    Circleoop(int x, int y);
    void setColor(int id = 0);
    void set(int x=0, int y=0, int r=0);
    int countNiceR(int w, int h);
    void setText(QString txt);
    bool isXYinC(int x, int y);
    void drawInWidget(QPainter &p);
};

#endif // CIRCLEOOP_H
