#include "widget.h"
#include "game.h"
#include <QDebug>

widget::widget(QWidget *parent) : QGraphicsView(parent)
{
    int tx=sizeHint().width();
    int ty=sizeHint().height();
    RoundButton.set(tx/2, ty/2);
    RoundButton.countNiceR(tx, ty);
}

void widget::setColor(int id)
{
    setStyleSheet("background-color: " + Game::col[id].name());
}

void widget::setColor(QColor color)
{
    setStyleSheet("background-color: " + color.name());
}

void widget::setButtonColor(QColor color)
{
    Game::buttoncolor = color;

}

void widget::paintEvent(QPaintEvent *event)
{
    p.begin(viewport());
    p.setRenderHint(QPainter::Antialiasing);

    QPen pen;
    pen.setColor(buttonColor);//(Game::col[(Game::c1+8)%16]);
    p.setPen(pen);
    //qDebug() <<"COLOR: " << buttonColor << "ll";

    RoundButton.drawInWidget(p);
    
    p.end();
    QGraphicsView::paintEvent(event);
}

void widget::mousePressEvent(QMouseEvent *event)
{
    int x = event->x(); int y = event->y();
    x1=x; y1=y;
    if(RoundButton.isXYinC(x, y)) emit prssed();
}

void widget::resizeEvent(QResizeEvent *event)
{
    int x = event->size().width(); int y = event->size().height();

    RoundButton.set(x/2, y/2);
    RoundButton.countNiceR(x, y);
}
