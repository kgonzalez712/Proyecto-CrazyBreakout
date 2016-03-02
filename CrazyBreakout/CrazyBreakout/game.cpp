
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
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,800); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,800);
    setMouseTracking(true);

    // create the player
    player = new Player();
    player->setPos(200,750); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);
    player->grabMouse();
    player->spawn();

    createBlockGrid();

    // create the score/health
    score = new Score();
    scene->addItem(score);

//    // spawn enemies
//    QTimer * timer = new QTimer();
//    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
//    timer->start(2000);

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

