#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>
#include <QMediaPlayer>



class MyRect : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    MyRect(QGraphicsItem * parent = Q_NULLPTR);

protected:
    virtual void keyPressEvent(QKeyEvent * event);
    virtual void keyReleaseEvent(QKeyEvent *event);


    enum Direction {
        Direction_Left,
        Direction_Right,
        Direction_Unknown

    };

    Direction direction;

    bool isPressedLeft;
    bool isPressedRight;

public slots:
    void spawn();
    void move();

private:
    QMediaPlayer * _piu_sound;
    QTimer * _timer;
};


#endif // MYRECT_H
