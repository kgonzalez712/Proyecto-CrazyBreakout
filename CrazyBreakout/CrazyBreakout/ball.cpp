
/**
 *
 * @author Kevin
 *
 */


#include "ball.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "player.h"
#include <QDebug>



extern Game * game;

/**
 * @brief Ball::Ball this is the constructor
 * @param parent this inherits from the QT classes QObject QGraphicsPixmapItem and QGraphicsItem which eneables the ability to show and item on the UI in this case the ball.
 */

Ball::Ball(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/ball.png"));
    int random_number = rand() %900;
    setPos(random_number,500);
    xVel=3;
    yVel=10;
    deepLevel=0;
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

/**
 * @brief Ball::BorderCollision this method takes care of the collisions between the ball and the UI borders, keeping the ball in the game playable area.
 */
void Ball::BorderCollision(){
    double screenH = game->height();

    if (pos().x()< 0){
        xVel = -1 * xVel;
    }

    if (pos().x()>950){
        xVel = -1 * xVel;
    }

    if (pos().y()>screenH){
            scene()->removeItem(this);
            delete this;
            game->player->spawn();
        }

}

/**
 * @brief Ball::getDeepLevel this method returns the current deep level contained in the ball wich allows to destroy the border blocks
 * @return the deep level value.
 */
int Ball::getDeepLevel()
{
    return deepLevel;
}

/**
 * @brief Ball::setDeepLevel this method set the value for the deep level attribute
 */
void Ball::setDeepLevel()
{
    deepLevel = deepLevel + 1;
}

/**
 * @brief Ball::PlayerCollision this method takes care of the collisions between the ball and the player paddle(bar) this keeps the ball ricocheting arround to play the game
 */
void Ball::PlayerCollision()
{
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Player* player = dynamic_cast<Player*>(cItems[i]);
        if (player){
            double ballx = pos().x();
            double pc = player->getCenter();

            if (ballx < (pc + 5) & ballx > (pc -5 )){
                yVel = -1 * yVel;
            }
            if (ballx < (pc - 5)){
                xVel = 1 * xVel;
                yVel = -1 * yVel;
            }
            if (ballx > (pc + 5)){
                xVel =  1 * xVel;
                yVel = -1 * yVel;
            }
        }

            return;
        }
    }

/**
 * @brief Ball::CommonBlockCollision this method handles the collisions between the ball and the common blocks
 */
void Ball::CommonBlockCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
        for (size_t i = 0, n = cItems.size(); i < n; ++i){
            CommonBlock* cblock = dynamic_cast<CommonBlock*>(cItems[i]);
            if (cblock){
                double ballx = pos().x();
                int cpoints = cblock->getPoints();
                double cblockc = cblock->getCenter();


                if (ballx < (cblockc + 5) & ballx > (cblockc -5)){
                    yVel = -1 * yVel;
                }

                if (ballx < (cblockc - 5)){
                    xVel = -1 * 10;
                    yVel = -1 * yVel;

                }

                if (ballx > (cblockc + 5)){
                    xVel = -1 * -10;
                    yVel = -1 * yVel;

                }
                game->scene->removeItem(cblock);
                game->score->increase(cpoints);
                delete cblock;
            }
        }
}

/**
 * @brief Ball::DoubleBlockCollision this method handles the collisions between the ball and the double blocks
 */
void Ball::DoubleBlockCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
        for (size_t i = 0, n = cItems.size(); i < n; ++i){
            DoubleBlock* dblock = dynamic_cast<DoubleBlock*>(cItems[i]);
            if (dblock){
                double ballx = pos().x();
                int dpoints = dblock->getPoints();
                int dbpoints = dblock->getBPoints();
                double dblockc = dblock->getCenter();
                if (ballx < (dblockc + 5) & ballx > (dblockc -5)){
                    yVel = -1 * yVel;
                    dbpoints = dbpoints - 1;
                }
                 dbpoints = dbpoints - 1;
                if (ballx < (dblockc - 5)){
                    xVel = -1 * xVel;
                    yVel = -1 * yVel;
                    dbpoints = dbpoints - 1;
                }

                if (ballx > (dblockc + 5)){
                    xVel = -1 * xVel;
                    yVel = -1 * yVel;
                    dbpoints = dbpoints - 1;
                }
                game->scene->removeItem(dblock);
                game->score->increase(dpoints);
                delete dblock;
            }
        }
}

/**
 * @brief Ball::TripleBlockCollision this method handles the collisions between the ball and the triple blocks
 */
void Ball::TripleBlockCollision()
{
    QList<QGraphicsItem*> cItems = collidingItems();
        for (size_t i = 0, n = cItems.size(); i < n; ++i){
            TripleBlock* tblock = dynamic_cast<TripleBlock*>(cItems[i]);
            if (tblock){
                double ballx = pos().x();
                int tpoints = tblock->getPoints();
                int tbpoints = tblock->getBPoints();
                double tblockc = tblock->getCenter();
                if (ballx < (tblockc + 5) & ballx > (tblockc -5)){
                    yVel = -1 * yVel;
                    tbpoints = tbpoints - 1;
                }
                if (ballx < (tblockc - 5)){
                    xVel = -1 * xVel;
                    yVel = -1 * yVel;
                    tbpoints = tbpoints - 1;
                }

                if (ballx > (tblockc + 5)){
                    xVel = -1 * xVel;
                    yVel = -1 * yVel;
                    tbpoints = tbpoints - 1;
                }
                game->scene->removeItem(tblock);
                game->score->increase(tpoints);
                delete tblock;
            }
        }
}

/**
 * @brief Ball::SurpriseBlockCollision this method handles the collisions between the ball and the surprise blocks
 */
void Ball::SurpriseBlockCollision(){
QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        SurpriseBlock* sblock = dynamic_cast<SurpriseBlock*>(cItems[i]);
        if (sblock){
            double ballx = pos().x();
            double sblockc = sblock->getCenter();


            if (ballx < (sblockc + 5) & ballx > (sblockc -5)){
                yVel = -1.5 * yVel;
            }

            if (ballx < (sblockc - 5)){
                xVel = -1.5 * xVel;
                yVel = -1.5 * yVel;

            }

            if (ballx > (sblockc + 5)){
                xVel = -1.5 * xVel;
                yVel = -1.5 * yVel;

            }
            game->scene->removeItem(sblock);
            delete sblock;
        }
    }
}

/**
 * @brief Ball::DeepBlockCollision this method handles the collisions between the ball and the deep blocks
 */
void Ball::DeepBlockCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
        for (size_t i = 0, n = cItems.size(); i < n; ++i){
            DeepBlock* dpblock = dynamic_cast<DeepBlock*>(cItems[i]);
            if (dpblock){
                this->setDeepLevel();
                qDebug() << "DeepLevel increased" ;
                double ballx = pos().x();
                double dpblockc = dpblock->getCenter();
                if (ballx < (dpblockc + 5) & ballx > (dpblockc -5)){
                    yVel = -1 * yVel;
                }

                if (ballx < (dpblockc - 5)){
                    xVel = 1 * xVel;
                    yVel = 1 * yVel;

                }

                if (ballx > (dpblockc + 5)){
                    xVel = -1 * xVel;
                    yVel = -1 * yVel;

                }
            }
        }
}

/**
 * @brief Ball::BorderBlockCollision this method handles the collisions between the ball and the border blocks
 */
void Ball::BorderBlockCollision(){
QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        BorderBlock* bblock = dynamic_cast<BorderBlock*>(cItems[i]);
        if (bblock){
            double ballx = pos().x();
            int bpoints = bblock->getPoints();
            double bblockc = bblock->getCenter();


            if (ballx < (bblockc + 5) & ballx > (bblockc -5)){
                yVel = -1 * yVel;
            }

            if (ballx < (bblockc - 5)){
                xVel = -1 * 10;
                yVel = -1 * yVel;

            }

            if (ballx > (bblockc + 5)){
                xVel = -1 * -10;
                yVel = -1 * yVel;

            }
            if (this->getDeepLevel()<0){
                game->scene->removeItem(bblock);
                game->score->increase(bpoints);
                delete bblock;
            }
            else{
                return ;
            }
        }
    }
}

/**
 * @brief Ball::move this methods handles the movement of the ball
 */
void Ball::move(){
    setPos(x()+xVel,y()+yVel);
    PlayerCollision();
    BorderCollision();
    CommonBlockCollision();
    DoubleBlockCollision();
    TripleBlockCollision();
    DeepBlockCollision();
    SurpriseBlockCollision();

}
