#include "colorfulscore.h"
#include "QDebug"
#include <QIcon>
#include <QPainter>

ColorfulScore::ColorfulScore(QWidget *parent) : QLCDNumber(parent)
{
    display(0);
    setDigitCount(4);
    setSegmentStyle(SegmentStyle::Flat);
}

void ColorfulScore::null()
{
    the_score=0;
    display(0);
}

void ColorfulScore::up()
{
    display(++the_score);
}

void ColorfulScore::showHP(QColor color)
{
    first_time=0;
    setStyleSheet("*{ background: qlineargradient( x1:0 y1:0, x2:0 y2:1, stop:0 #a5a5a5, stop:1" + color.name() + ");}");
}

int ColorfulScore::score()
{
    return the_score;
}

void ColorfulScore::action(bool winOrLoose)
{
    //1 - win  // 0 - loose
    first_time=0;
    if(winOrLoose)setStyleSheet("*{ background: qlineargradient( x1:0 y1:0, x2:0 y2:1, stop:0 #a5a5a5, stop:1 #2eb240);}");
    else          setStyleSheet("*{ background: qlineargradient( x1:0 y1:0, x2:0 y2:1, stop:0 #a5a5a5, stop:1 #c51b1b);}");

}

void ColorfulScore::init()
{
    //no need so far
}

void ColorfulScore::mousePressEvent(QMouseEvent *ev)
{
    if(first_time)
    {
        setStyleSheet("*{}");
        first_time=0;
    }
    emit onPres();
}

void ColorfulScore::paintEvent(QPaintEvent *ev)
{
    if(first_time)
    {
        QPainter p;
        p.begin(this);

        QPen pen;
        pen.setWidth(t/75+1);
        p.setPen(pen);

        int x, y;
        x = abs((xc-t))/2;
        y = abs((yc-t))/2;

        p.drawRect(x+t/8, y+3*t/8, t/8, t/4);
        p.drawLine(x+t/4, y+3*t/8, x+t/2, y+t/8);
        p.drawLine(x+t/4, y+5*t/8, x+t/2, y+7*t/8);
        p.drawEllipse(QPoint(x+t/2, y+t/2), t/16, 3*t/8);

        p.drawLine(x+5*t/16, y+7*t/16, x+3*t/8, y+3*t/8);
        p.drawLine(x+5*t/16, y+t/2, x+3*t/8, y+t/2);
        p.drawLine(x+5*t/16, y+9*t/16, x+3*t/8, y+5*t/8);

        p.drawLine(x, y, x+t, y+t);
        p.drawLine(x+t, y, x, y+t);
        p.end();
    }
    else QLCDNumber::paintEvent(ev);
}

void ColorfulScore::resizeEvent(QResizeEvent *ev)
{
    QLCDNumber::resizeEvent(ev);
    xc = ev->size().width();
    yc = ev->size().height();
    t = std::min(xc, yc);

}
