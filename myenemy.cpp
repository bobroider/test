
#include <cstdlib>
#include <algorithm>

#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <QtAlgorithms>

#include "myenemy.h"
#include "game.h"

extern Game * game;

MyEnemy::MyEnemy()
{
    setRect(0, 0, 100, 100);
    setPos(rand() % 700, -100);
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

MyEnemy::~MyEnemy()
{
    qDebug() << "Delete Enemy";
}

void MyEnemy::move()
{
    moveBy(0, 5);
    if (pos().y() > scene()->sceneRect().bottom() ) {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
