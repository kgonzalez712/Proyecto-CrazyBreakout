#ifndef BALL_H
#define BALL_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <typeinfo>
#include <player.h>

class Ball: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ball(QGraphicsItem * parent=0);

private:
    double xVel;
    double yVel;
    int deepLevel;

    void PlayerCollision();
    void CommonBlockCollision();
    void DoubleBlockCollision();
    void TripleBlockCollision();
    void SurpriseBlockCollision();
    void DeepBlockCollision();
    void BorderBlockCollision();
    void BorderCollision();
    int getDeepLevel();
    void setDeepLevel();


public slots:
    void move();
};

#endif // BALL_H
