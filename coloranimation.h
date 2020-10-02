#ifndef COLORANIMATION_H
#define COLORANIMATION_H
#include <QColor>
#include "circleoop.h"
#include "game.h"
class coloranimation
{
public:
    coloranimation();
    void startAnimation(QColor col1, QColor col2);
    QColor animate();
private:

    float c1[3];//R, G, B
    float c2[3];
    const float a = 9;
    float x = a;//coefficient of transition

};

#endif // COLORANIMATION_H
