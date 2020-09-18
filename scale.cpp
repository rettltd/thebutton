#include "scale.h"
#include <QFontMetrics>
#include <QDebug>
int scale::width;
int scale::height;
QFont scale::textResize(QFont font, QString str, QSize bW)
{

    font.setPixelSize(10);
    /*do{
        QFontMetrics fm(font);
        qDebug() << fm.horizontalAdvance(str) << bW.width();
        if(fm.horizontalAdvance(str) < bW.width()){
            font.setPixelSize(font.pixelSize() + 1);
        }
        else break;
    }while(true);*/
    QFontMetrics qfm(font);
    font.setPixelSize((bW.height()+bW.width())*0.1);
    //font.setPixelSize(font.pixelSize() - 1);
    return font;
}

scale::scale()
{

}

///QSize (height,width)
