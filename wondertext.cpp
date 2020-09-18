#include "wondertext.h"
#include "game.h"
#include "scale.h"
#include <QFontDatabase>
#include <QFont>

QFont WonderText::font;

WonderText::WonderText(QWidget *parent) : QLabel(parent)
{
    id = QFontDatabase::addApplicationFont(":/fonts/UbuntuMono-Bold.ttf");
    family = QFontDatabase::applicationFontFamilies(id).at(0);
    font = QFont(family);


    /*QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(-1, -1);
    effect->setColor(Qt::yellow);
    setGraphicsEffect(effect);*/
}

void WonderText::set(int number)
{
    f_s = number;

    //font = scale().textResize(font, "++++++++++", size());
    font.setBold(true);
    //font.setPixelSize(sizeHint().height()/10);
    setFont(font);
    setStyleSheet("color: " + Game::col[Game::color2].name());
    setAlignment(Qt::AlignmentFlag::AlignCenter);
    if(f_s)
    {
        setStyleSheet("color: " + Game::col[Game::color1].name());
    }
    else setStyleSheet("color: " + Game::col[Game::color2].name());
}

void WonderText::set(QString tx)
{
    //font.setBold(true);
    //font.setPixelSize(sizeHint().height()/10);
    //setFont(font);
    setAlignment(Qt::AlignmentFlag::AlignCenter);
    setText(tx);

}

void WonderText::setColor(int id)
{
    setStyleSheet("color: " + Game::col[id].name());
}

void WonderText::updatetxt()
{

    if(f_s)
    {
        setText(Game::cs[Game::color2]);
        setStyleSheet("color: " + Game::col[Game::color2].name());
    }
    else
    {
        setText(Game::cs[Game::color1]);
        setStyleSheet("color: " + Game::col[Game::color1].name());
    }
}

void WonderText::action(bool winOrLoose)
{
    //1 - win  // 0 - loose
    if(winOrLoose)setStyleSheet("*{ background: qlineargradient( x1:0 y1:0, x2:0 y2:1, stop:0 #a5a5a5, stop:1 #2eb240);}");
    else          setStyleSheet("*{ background: qlineargradient( x1:0 y1:0, x2:0 y2:1, stop:0 #a5a5a5, stop:1 #c51b1b);}");

}

QSize WonderText::minimumSizeHint() const
{
    return QSize(0, 0);
}

void WonderText::resizeEvent(QResizeEvent *event)
{
    //font = scale().textResize(font, "++++++++++", event->size());
    int temp = static_cast<int>(event->size().height()+event->size().width()*0.2);
    font.setPixelSize(temp/6);
    setFont(font);
}

