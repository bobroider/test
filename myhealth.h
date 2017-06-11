#ifndef MYHEALTH_H
#define MYHEALTH_H

#include <QGraphicsTextItem>

class MyHealth : public QGraphicsTextItem
{
public:
    MyHealth(QGraphicsItem * parent = Q_NULLPTR);


    void decrease();
    int health();
private:
    int _health;
};

#endif // MYHEALTH_H
