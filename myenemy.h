#ifndef MYENEMY_H
#define MYENEMY_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>
#include <QDebug>

class MyEnemy : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    MyEnemy();
    virtual ~MyEnemy();


    enum { Type = UserType + 1 };
    int type() const { return Type; }

public slots:
    void move();

};


#endif // MYENEMY_H
