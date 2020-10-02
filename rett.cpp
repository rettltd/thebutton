#include "rett.h"
#include "widget.h"
rett::rett(QWidget *parent) : QMainWindow(parent)
{

    m.setParent(this);
    setCentralWidget(&m);
    connect(&timew, &QTimer::timeout, this, &rett::onTimeout);
    timew.start(25);
    pllst.addMedia(QMediaContent(QUrl("qrc:/sound/untitled2.mp3")));
    pllst.setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    musisch.setPlaylist(&pllst);
    musisch.play();
}

rett::~rett()
{

}

void rett::onTimeout()
{
    update();
    m.animation();
    m.onTimeout();
}

void rett::musikAFK()
{
    QApplication* app1 = qobject_cast<QApplication*>(sender());
    int backgr = app1->applicationState();
    switch (backgr) {
    case Qt::ApplicationState::ApplicationActive:
        musisch.play();
        break;
    case Qt::ApplicationState::ApplicationHidden:
        musisch.pause();
        break;
    case Qt::ApplicationState::ApplicationInactive:
        musisch.pause();
        break;
    case Qt::ApplicationState::ApplicationSuspended:
        musisch.pause();
        break;
    default:
        break;
    }
}

