#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "ball.h"
#include <QBrush>

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    size=130;
    // drew the rect
    setRect(0,0,size,10);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void Player::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    // follow mouse's x pos
    double mouseX = mapToScene(event->pos()).x();
    setPos(mouseX,y());
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        setPos(x()-20,y());
        if (pos().x()<=-5){
            setPos(x()+20,y());
        }
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+20,y());
        if(pos().x()>700){
            setPos(x()-20,y());
        }
    }
}

int Player::getSize(){
    return size;
}


double Player::getCenter()
{
    return x()+rect().width()/2;
}

void Player::spawn(){
    // create an enemy
    Ball * ball = new Ball();
    scene()->addItem(ball);
}
