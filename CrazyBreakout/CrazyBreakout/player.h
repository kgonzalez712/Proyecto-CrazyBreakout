
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>


class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    double getCenter();
    int getSize();
private:
    int size;
public slots:
    void spawn();
};

#endif // PLAYER_H
