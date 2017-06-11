#ifndef MYBULLET_H
#define MYBULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>

#include "myenemy.h"



class MyBullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    MyBullet();
    virtual ~MyBullet();

    enum { Type = UserType + 2 };
    int type() const { return Type; }


public slots:
    void move();

private:
    bool _need_remove;
};


#endif // MYBULLET_H
