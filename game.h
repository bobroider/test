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
    Game();

    QGraphicsView * view;
    QGraphicsScene * scene;
    MyRect * player;
    MyScore * score;
    MyHealth * health;

    void show();
};

#endif // GAME_H
