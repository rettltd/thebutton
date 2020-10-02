#include "circleoop.h"
#include "game.h"
#include <QDebug>
#include "wondertext.h"
#include "scale.h"
#include <math.h>

Circleoop::Circleoop()
{

}

Circleoop::Circleoop(int x, int y) : xc(x), yc(y)
{

}

void Circleoop::setColor(int id)
{
    ccolor = id;
}

void Circleoop::set(int x, int y, int r)
{
    xc=x; yc=y; radius=r;
}

int Circleoop::countNiceR(int w, int h)
{
    return radius=static_cast<int>(0.14*(w+h));
}

void Circleoop::setText(QString txt)
{
    //qDebug() << txt;
    text = txt;
    fonT = WonderText::font;
}

bool Circleoop::isXYinC(int x, int y)
{
    return (xc-x)*(xc-x)+(yc-y)*(yc-y) <= radius*radius*1.05*1.05;
}

void Circleoop::drawInWidget(QPainter &p)
{
    QBrush br(Qt::BrushStyle::SolidPattern);
    QPainterPath ppth2;
    ppth2.addEllipse(QPointF(xc, yc), radius*1.05, radius*1.05);

    QPainterPath ppth;
    ppth.addEllipse(QPointF(xc, yc), radius, radius);

    br.setColor(Qt::black);
    p.fillPath(ppth2, br);
    br.setColor(Game::buttoncolor);//(Game::col[Game::c1]);
    p.fillPath(ppth, br);
    if(text == "") return;
    QRect rkt;
    QFontMetrics qfm(fonT);

    fonT.setPixelSize(radius/3);

    //int t1 = qfm.height()*2;
    //int x2 = sqrt(abs((radius-t1/2)*(radius+t1/2)));

    //if(qfm.horizontalAdvance(text) > 2*radius)
    //{
       int t1 = qfm.height()*3;
       int x2 = sqrt(abs((radius-t1/2)*(radius+t1/2)));
        //rkt.setRect(xc-x2, yc-t1, 2*x2, t1);
    //}
    rkt.setRect(xc-x2, yc-t1*0.5, 2*x2, t1);
    p.setFont(fonT);
    //qDebug() << rkt.size() << " " << radius;
    p.drawText(rkt, Qt::TextFlag::TextWordWrap, text);

}



