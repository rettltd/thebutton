#ifndef WIDGET_H
#define WIDGET_H

#include <math.h>

#include <QWidget>
#include <QPainter>
#include <QBrush>
#include <QGraphicsView>
#include <QMouseEvent>
#include "circleoop.h"

class widget : public QGraphicsView
{
    Q_OBJECT
public:

    Circleoop RoundButton;
    explicit widget(QWidget *parent = nullptr);
    void setColor(int id);
    void setColor(QColor color);
protected:

    int x1=0, y1=0;

    QPainter p;

    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

signals:
    void prssed();

public slots:
};

#endif // WIDGET_H
