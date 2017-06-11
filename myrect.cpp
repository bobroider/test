
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myrect.h"
#include "mybullet.h"
#include "myenemy.h"
#include "game.h"

MyRect::MyRect(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
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
    if (event->key() == Qt::Key_Left) {
        event->accept();
        direction = Direction_Left;
        _timer->start();
    }
    else if (event->key() == Qt::Key_Right) {
        event->accept();
        direction = Direction_Right;
        _timer->start();
    }
    else if (event->key() == Qt::Key_Space) {
        event->accept();
        scene()->addItem(new MyBullet);

        if (_piu_sound->state() == QMediaPlayer::PlayingState) {
            _piu_sound->setPosition(0);
        }
        else if(_piu_sound->state() == QMediaPlayer::StoppedState) {
            _piu_sound->play();
        }
    }
    else
        event->ignore();
}

void MyRect::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()) { event->ignore(); return; }
    if (event->key() == Qt::Key_Left) {
        event->accept();
        _timer->stop();
    }
    else if (event->key() == Qt::Key_Right) {
        event->accept();
        _timer->stop();
    }
}

void MyRect::spawn()
{
    scene()->addItem(new MyEnemy);
}

void MyRect::move()
{
    if(!hasFocus() && _timer->isActive()) { _timer->stop(); return; }
    if(direction == Direction_Left) {
        if(pos().x() > 0)
            moveBy(-1, 0);
        else
            _timer->stop();
    } else {
        if (pos().x() + boundingRect().width() < scene()->sceneRect().right())
            moveBy(1, 0);
        else
            _timer->stop();
    }
}

