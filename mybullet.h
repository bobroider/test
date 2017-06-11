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
    struct CheckCollisionEnemy {
        MyBullet * _delegate;

        CheckCollisionEnemy(MyBullet * delegate): _delegate(delegate) {}

        void operator()(QGraphicsItem * item) {
            if (item->type() == MyEnemy::Type) {
                item->scene()->removeItem(item);
                delete item;
                _delegate->_need_remove = true;
            }

        }
    };

public slots:
    void move();

private:
    bool _need_remove;
};


#endif // MYBULLET_H
