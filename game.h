#ifndef GAME_H
#define GAME_H
#include <QColor>
#include <QTimer>
#include <QString>
#include "widget.h"
class Game
{
public:
    static int color1;
    static int color2;
    static int c1;
    static int c2;
    static QColor buttoncolor;
    static const QColor col[16];
    static const QString cs[16];

    int tick, currentTick;
    bool flag1=0;
    Game();
    bool check();
    void update(widget &W);
    void generate();
private:
};


#endif // GAME_H
