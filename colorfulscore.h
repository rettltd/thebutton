#ifndef COLORFULSCORE_H
#define COLORFULSCORE_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QResizeEvent>

class ColorfulScore : public QLCDNumber
{
    Q_OBJECT
public:
    int the_score=0;
    bool first_time=1;

    explicit ColorfulScore(QWidget *parent = nullptr);

    void null();
    void up();
    void showHP(QColor color);
    int score();
    void action(bool winOrLoose);

    void init();

protected:
    int xc, yc, t;
    void mousePressEvent(QMouseEvent *ev) override;
    void paintEvent(QPaintEvent *ev) override;
    void resizeEvent(QResizeEvent *ev) override;
signals:

    void onPres();
public slots:
};

#endif // COLORFULSCORE_H
