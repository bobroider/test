#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>


#include "myrect.h"

#include "score.h"
#include "myhealth.h"

class Game {

public:
    static const int _w = 800;
    static const int _h = 600;
    enum PriorityDeepLevel {
        PriorityDeepPlayer = 2,
        PriorityDeepEnemy = 1,
        PriorityDeepBullet = 0
    };

    Game();

    QGraphicsView * view;
    QGraphicsScene * scene;
    MyRect * player;
    MyScore * score;
    MyHealth * health;

    void show();
};

#endif // GAME_H
