#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class MyScore : public QGraphicsTextItem {
public:
    MyScore(QGraphicsItem * parent = Q_NULLPTR);

    void increase();
    int score();

private:
    int _score;
};

#endif // SCORE_H
