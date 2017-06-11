
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myrect.h"
#include "mybullet.h"
#include "myenemy.h"
#include "game.h"

MyRect::MyRect(QGraphicsItem *parent): QGraphicsPixmapItem(parent), direction(Direction_Unknown)
{
    _piu_sound = new QMediaPlayer;
    _piu_sound->setMedia(QUrl("qrc:/music/piu.wav"));
    _timer = new QTimer(this);
    _timer->setInterval(5);

    connect( _timer, SIGNAL(timeout()), this, SLOT(move()));

    setPixmap(QPixmap(":/image/fly.png"));
    setZValue(Game::PriorityDeepPlayer);
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()) { event->ignore(); return; }

    switch (event->key()) {
    case Qt::Key_Left:
        isPressedLeft = true;
        if(!isPressedRight) direction = Direction_Left;
        break;

    case Qt::Key_Right:
        isPressedRight = true;
        if(!isPressedLeft) direction = Direction_Right;
        break;

    case Qt::Key_Space:
        event->accept();
        scene()->addItem(new MyBullet);
        if (_piu_sound->state() == QMediaPlayer::PlayingState) {
            _piu_sound->setPosition(0);
        }
        else if(_piu_sound->state() == QMediaPlayer::StoppedState) {
            _piu_sound->play();
        }
        return;
        break;

    default:
        event->ignore();
        return;
    }
    event->accept();
    _timer->start();

}

void MyRect::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()) { event->ignore(); return; }

    switch (event->key()) {
    case Qt::Key_Left:
        isPressedLeft = false;
        if(isPressedRight) direction = Direction_Right;
        else _timer->stop();
        break;

    case Qt::Key_Right:
        isPressedRight = false;
        if(isPressedLeft) direction = Direction_Left;
        else _timer->stop();
        break;
    default:
        event->ignore();
        return;
    }
}

void MyRect::spawn()
{
    scene()->addItem(new MyEnemy);
}

void MyRect::move()
{
    if(!hasFocus()) { _timer->stop(); return; }

    if(direction == Direction_Left) {
        if(pos().x() > 0)
            moveBy(-1, 0);
        else {
            //_timer->stop();
            direction = Direction_Unknown;
        }
    } else if(direction == Direction_Right){
        if (pos().x() + boundingRect().width() < scene()->sceneRect().right())
            moveBy(1, 0);
        else {
            //_timer->stop();
            direction = Direction_Unknown;
        }
    }
}

