
/**
 *
 * @author Kevin
 *
 */

#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "ball.h"
#include <QBrush>

/**
 * @brief Player::Player This is the class constructor it sets the paddle so the player can play
 * @param parent
 */
Player::Player(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    size=130;
    setRect(0,0,size,10);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

/**
 * @brief Player::mouseMoveEvent this method eneables the player to move the paddle with the mouse to play the game
 * @param event
 */
void Player::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    double mouseX = mapToScene(event->pos()).x();
    setPos(mouseX,y());
}

/**
 * @brief Player::keyPressEvent this method enebles the player to move using the arrow keys on the keyboard
 * @param event
 */
void Player::keyPressEvent(QKeyEvent *event){
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

/**
 * @brief Player::getSize this method gets the paddle size of the player
 * @return the value of the attribute size
 */
int Player::getSize(){
    return size;
}

/**
 * @brief Player::getCenter this method retruns the center of the player's paddle
 * @return
 */
double Player::getCenter()
{
    return x()+rect().width()/2;
}

/**
 * @brief Player::spawn this method spawn a  ball object each time a player is created or the ball go out of bounds
 */
void Player::spawn(){
    Ball * ball = new Ball();
    scene()->addItem(ball);
}
