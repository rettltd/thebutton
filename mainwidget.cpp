#include "mainwidget.h"
#include <QDebug>
#include "rett.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    ok_sound.setSource(QUrl("qrc:/sound/404878__gnuoctathorpe__bassdrum-13.wav"));
    misclick_sound.setSource(QUrl("qrc:/sound/407478__loyalty-freak-music__drop.wav"));
    lose_sound.setSource(QUrl("qrc:/sound/428076__pschrandt__sad-blub.wav"));
    //start_sound.setSource(QUrl("qrc:/sound/444453__punisherdan__timeout.wav"));

    QSizePolicy qspol(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget* masiv[4]{&widg, &score1, &text1, &text2};
    for (int i = 0; i < 4; i++)
    {
        masiv[i]->setSizePolicy(qspol);
        masiv[i]->setParent(this);
    }
    //text1.setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
    //text2.setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
    text1.set(0);// text1.updatetxt();
    text2.set(1);// text2.updatetxt();
    text1.set("Tap button\nif 2 colors\nmatch!");
    text2.set("Order does\nNOT matter!");
    text1.setColor(5);
    text2.setColor(5);
    score1.null();
    score1.init();
    //score1.showHP(hpC[hp]);

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
    Game::c1 = 5;
}

void MainWidget::onTimeout()
{
    timer += 25;
    if(isGame)
    {
        if(timer >= speed)
        {
            game.update(widg);
            text1.updatetxt();
            text2.updatetxt();
            text1.update();
            text2.update();

            timer = 0;
        }
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
            //score1.action(1);
            if(score1.score() % 3 == 0)
            {
                speed *= 0.9*(speed>300);
                //qDebug() << speed;
            }
        }
        else
        {
            // u los helth
            text1.action(0);
            text2.action(0);
            //score1.action(0);
            score1.showHP(hpC[--hp]);
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
    }
    else
    {
        isGame = 1;
        score1.null();
        score1.showHP(hpC[hp=3]);
        widg.RoundButton.setText("");
        //start_sound.play();
        ok_sound.play();
    }
}

void MainWidget::audioNull()
{
    audioOff=!audioOff;

    ok_sound.setMuted(audioOff);
    lose_sound.setMuted(audioOff);
    misclick_sound.setMuted(audioOff);
    //start_sound.setMuted(audioOff);

    ok_sound.setVolume(!audioOff);
    lose_sound.setVolume(0.5*!audioOff);
    misclick_sound.setVolume(!audioOff);
    //start_sound.setVolume(!audioOff);

    rett& r = dynamic_cast<rett&>(*parent());
    r.musisch.setMuted(audioOff);
}
