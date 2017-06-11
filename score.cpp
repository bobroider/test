#include <QString>
#include <QFont>
#include "score.h"


MyScore::MyScore(QGraphicsItem *parent): QGraphicsTextItem(parent), _score(0)
{
    setPlainText(QString("Score: ") + QString::number(_score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void MyScore::increase()
{
    ++_score;
    setPlainText(QString("Score: ") + QString::number(_score));
}

int MyScore::score()
{
    return _score;
}



