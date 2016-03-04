
/**
 *
 * @author Kevin
 *
 */

#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "ball.h"
#include <QBrush>
#include <QImage>
#include "commonblock.h"

/**
 * @brief Game::Game This is the class constructor, it establishes all elements of the UI the scene,the view and set the objects in the view.
 * @param parent
 */
Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,800); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,800);
    setMouseTracking(true);

    player = new Player();
    player->setPos(200,750);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    player->grabMouse();
    player->spawn();

    createBlockGrid();

    score = new Score();
    scene->addItem(score);

    show();

}

/**
 * @brief Game::createBlockGrid this method creates the block grid that the playe has to drestroy
 */
void Game::createBlockGrid()
{
    for(int i=0;i<10;i++){
        cblock = new CommonBlock();
        cblock->setPos(i*100,240);
        scene->addItem(cblock);
        dblock = new DoubleBlock();
        dblock->setPos(i*100,210);
        scene->addItem(dblock);
        tblock = new TripleBlock();
        tblock->setPos(i*100,170);
        scene->addItem(tblock);
        sblock = new SurpriseBlock();
        sblock->setPos(i*100,125);
        scene->addItem(sblock);
        dpblock = new DeepBlock();
        dpblock->setPos(i*100,55);
        scene->addItem(dpblock);
        bblock = new BorderBlock();
        bblock->setPos(i*100,25);
        scene->addItem(bblock);

    }
}

