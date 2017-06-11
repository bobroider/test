#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QObject>

#include <QMediaPlayer>

class MyRect : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    MyRect(QGraphicsItem * parent = Q_NULLPTR);
protected:
    virtual void keyPressEvent(QKeyEvent * event);

public slots:
    void spawn();

private:
    QMediaPlayer * _piu_sound;
};


#endif // MYRECT_H
