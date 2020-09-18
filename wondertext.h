#ifndef WONDERTEXT_H
#define WONDERTEXT_H

#include <QWidget>
#include <QLabel>
#include <QResizeEvent>
#include <QPainter>
#include <QString>

class WonderText : public QLabel
{
    Q_OBJECT
public:
    int f_s=0;
    bool fl=0;
    static QFont font;
    void action(bool winOrLoose);
    explicit WonderText(QWidget *parent = nullptr);
    void set(int number);
    void set(QString tx);
    void setColor(int id);
    void updatetxt();
protected:
    int id;
    QString family;
    QPainter p;

    QSize minimumSizeHint() const override;
    void resizeEvent(QResizeEvent* event) override;
signals:

public slots:
};

#endif // WONDERTEXT_H
