
#include <QTimer>
#include <QMediaPlayer>

#include "game.h"



Game::Game()
{
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 800, 600);

    player = new MyRect;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);


    view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->adjustSize();
    view->setFixedSize(view->size());


    player->setPos(scene->width() / 2, scene->height() - player->boundingRect().height());

    score = new MyScore;
    scene->addItem(score);
    health = new MyHealth;
    health->setPos(0, score->pos().y() + score->boundingRect().bottom());
    scene->addItem(health);

    // add back sound
    QMediaPlayer * bgmedia = new QMediaPlayer;
    bgmedia->setMedia(QUrl("qrc:/music/bgsound.mp3"));
    bgmedia->play();

    QTimer * timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

}

void Game::show()
{
    view->show();
}
