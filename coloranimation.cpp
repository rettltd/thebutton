#include "coloranimation.h"
#include <QDebug>
coloranimation::coloranimation()
{
    //c1[0] = (float)(color1.red());  c1[1] = (float)(color1.green());  c1[2] = (float)(color1.blue());
    //c2[0] = (float)(color2.red());  c2[1] = (float)(color2.green());  c2[2] = (float)(color2.blue());
}

void coloranimation::startAnimation(QColor col1 = QColor(0,255,0), QColor col2 = QColor(0,0,0))
{
    ///qDebug() << "{color1 : " << col1 << ", color2 : " << col2 << "}";
    x = 0;//"distance" from c1 to c2
    c2[0] = col1.red(); c2[1] = col1.green(); c2[2] = col1.blue();
    c1[0] = (col2.red()-col1.red()) ; c1[1] =(col2.green()-col1.green()); c1[2] = (col2.blue()-col1.blue());
    //c1[0] = (col1.red() - c2[0])/45000; c1[1] = (col1.green() - c2[1])/4500; c1[2] = (col1.blue() - c2[2])/45000;

}

QColor coloranimation::animate()
{
    if(x >= a)return QColor(c1[0] * (int)(x / a) + c2[0], c1[1] * (int)(x / a) + c2[1], c1[2] * (int)(x / a) + c2[2]);
    int col_red = c1[0] * (x / a) + c2[0];
    int col_green = c1[1] * (x / a) + c2[1];
    int col_blue = c1[2] * (x / a) + c2[2];
    x++;//reduce distance
    ///qDebug() << "[red : "<< col_red << "green : " << col_green << "blue : " << col_blue <<" x = " << x << " x/a =  " <<  (int)(x/a) <<  "]";
    return QColor(col_red, col_green, col_blue);
}
