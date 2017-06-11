#include <QString>
#include <QFont>
#include "myhealth.h"

MyHealth::MyHealth(QGraphicsItem *parent): QGraphicsTextItem(parent), _health(3)
{
    setPlainText(QString("Health: ") + QString::number(_health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void MyHealth::decrease()
{
    --_health;
    setPlainText(QString("Health: ") + QString::number(_health));
}

int MyHealth::health()
{
    return _health;
}
