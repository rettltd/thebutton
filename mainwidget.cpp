#include "mainwidget.h"
#include <QDebug>
#include "rett.h"

void MainWidget::animation()
{

    //animation after button press
    if(totalrad)
    {
        if(widg.RoundButton.radius >= totalrad * 0.9 && anim)
        {
            widg.RoundButton.radius -= totalrad * 0.02;
        }
        else
        {
            anim = 0;
            if(widg.RoundButton.radius < totalrad && !anim)
            {
                widg.RoundButton.radius += totalrad * 0.02;
            }
            else totalrad = 0;
            qDebug() << "[RADIUS = " << widg.RoundButton.radius << "]" << endl;
        }
    }
    widg.setColor(col.animate());
    widg.setButtonColor(col_1.animate());
}

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    ok_sound.setSource(QUrl("qrc:/sound/404878__gnuoctathorpe__bassdrum-13.wav"));
    misclick_sound.setSource(QUrl("qrc:/sound/407478__loyalty-freak-music__drop.wav"));
    lose_sound.setSource(QUrl("qrc:/sound/428076__pschrandt__sad-blub.wav"));


    QSizePolicy qspol(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget* masiv[4] {&widg, &score1, &text1, &text2};
    for (int i = 0; i < 4; i++)
    {
        masiv[i]->setSizePolicy(qspol);
        masiv[i]->setParent(this);
    }
    text1.set(0);
    text2.set(1);
    text1.set("Tap button\nif 2 colors\nmatch!");
    text2.set("Order does\nNOT matter!");
    text1.setColor(5);
    text2.setColor(5);
    score1.null();
    score1.init();


    glay = new QGridLayout(this);
    glay->setSpacing(0);
    glay->setContentsMargins(0,0,0,0);
    glay->setRowStretch(0, 1);
    glay->setRowStretch(1, 5);
    glay->setColumnStretch(0, 2);
    glay->setColumnStretch(1, 2);
    glay->setColumnStretch(2, 1);

    glay->addWidget(&widg, 1, 0, 1, 3);
    glay->addWidget(&score1, 0, 2, 1, 1);
    glay->addWidget(&text1, 0, 0, 1, 1);
    glay->addWidget(&text2, 0, 1, 1, 1);

    connect(&widg, &widget::prssed, this, &MainWidget::onPrssed);
    connect(&score1, &ColorfulScore::onPres, this, &MainWidget::audioNull);

    timer = 0;
    isGame = 0;

    widg.RoundButton.setText("  TAP TO\n\n  START");
    Game::c1 = qrand() % 16;
    Game::c2 = qrand() % 16;

    //set colors of button and background

    ///set colors by changing 2nd color!
    col.startAnimation(QColor(0,0,0),game.col[game.c1]);
    col_1.startAnimation(QColor(0,0,0),game.col[game.c2]);
}

void MainWidget::onTimeout()
{
    timer += 25;
    if(isGame)
    {

        if(timer >= speed)
        {
            QColor oldColor = game.col[game.c2];
            QColor oldColor1 = game.col[game.c1];
            game.update(widg);
            text1.updatetxt();
            text2.updatetxt();
            text1.update();
            text2.update();
            col.startAnimation(oldColor,game.col[game.c2]);
            col_1.startAnimation(oldColor1,game.col[game.c1]);
            timer = 0;
        }

        // qDebug() <<  game.col[game.c1];
        widg.update();
        score1.update();

    }
    update();
    widg.viewport()->update();

}

void MainWidget::onPrssed()
{
    if(isGame)
    {
        if(game.check())
        {
            score1.up();
            ok_sound.play();
            text1.action(1);
            text2.action(1);
            if(score1.score() % 3 == 0)
            {
                speed *= 0.9*(speed>300);
            }
        }
        else
        {
            text1.action(0);
            text2.action(0);
            score1.showHP(hpC[--hp]);



            //widg.RoundButton.setRad(widg.RoundButton.radius * 0.8);

            if(hp<=0)
            {
                isGame = 0;
                widg.RoundButton.setText(" U LOOSE!\n  TAP TO\n RESTART!");
                lose_sound.play();
                speed = 1000;
                widg.setColor(QColor(0xffc51b1b));
                Game::c1 = 5;
                widg.viewport()->update();
            }
            else
                misclick_sound.play();
        }

        //start animation
        totalrad = widg.RoundButton.radius;
        anim = 1;
    }
    else
    {
        isGame = 1;
        score1.null();
        score1.showHP(hpC[hp=3]);
        widg.RoundButton.setText("");
        ok_sound.play();
    }
}

void MainWidget::audioNull()
{
    audioOff=!audioOff;

    ok_sound.setMuted(audioOff);
    lose_sound.setMuted(audioOff);
    misclick_sound.setMuted(audioOff);
    ok_sound.setVolume(!audioOff);
    lose_sound.setVolume(0.5*!audioOff);
    misclick_sound.setVolume(!audioOff);

    rett& r = dynamic_cast<rett&>(*parent());
    r.musisch.setMuted(audioOff);
}
