#include <iostream>
#include <ctime>
#include <cstdlib>

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <QLibraryInfo>
#include <QString>
#include <QTimer>

#include <QLoggingCategory>

#include "myrect.h"


#include "game.h"

Game * game;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    game = new Game;

    game->show();
    return a.exec();
}
