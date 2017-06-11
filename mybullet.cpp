#include <algorithm>

#include <QList>
#include <QGraphicsScene>
#include <QDebug>

#include "mybullet.h"
#include "game.h"

extern Game * game;


MyBullet::MyBullet() : QGraphicsPixmapItem(), _need_remove(false)
{
    //setRect(0,0,10, 50);

    setPixmap(QPixmap(":/image/Missile.png"));

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(5);

    MyRect * pl = game->player;
    setPos( pl->pos() + pl->boundingRect().center() - boundingRect().center() );
    setZValue(Game::PriorityDeepBullet);
    qDebug() << pl->pos() << pl->boundingRect().center() << boundingRect().center() << pl->zValue();

}

MyBullet::~MyBullet()
{
    qDebug() << "Delete bullet";
}

void MyBullet::move() {
    QList<QGraphicsItem *> items = collidingItems();

    std::for_each(items.begin(), items.end(), CheckCollisionEnemy(this));
    if(_need_remove) {
        game->score->increase();
        scene()->removeItem(this);
        delete this;
        return;
    }

    QRectF rect = boundingRect();
    moveBy(0, -1);
    if (y() + rect.height() <= 0) {
        scene()->removeItem(this);
        delete this;
    }
}
