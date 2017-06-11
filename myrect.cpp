
#include <QDebug>
#include <QGraphicsScene>

#include "myrect.h"
#include "mybullet.h"
#include "myenemy.h"

MyRect::MyRect(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    _piu_sound = new QMediaPlayer;
    _piu_sound->setMedia(QUrl("qrc:/music/piu.wav"));

    setPixmap(QPixmap(":/image/fly.png"));
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if(pos().x() > 0)
            moveBy(-10, 0);
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + boundingRect().width() < scene()->sceneRect().right())
            moveBy(10, 0);
    }
    else if (event->key() == Qt::Key_Space) {
        MyBullet * bullet = new MyBullet;
        bullet->setPos(x(), y());
        scene()->addItem(bullet);

        if (_piu_sound->state() == QMediaPlayer::PlayingState) {
            _piu_sound->setPosition(0);
        }
        else if(_piu_sound->state() == QMediaPlayer::StoppedState) {
            _piu_sound->play();
        }
    }
}

void MyRect::spawn()
{
    MyEnemy * enemy = new MyEnemy;
    scene()->addItem(enemy);
}
