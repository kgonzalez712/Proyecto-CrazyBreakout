/**
 *
 * @author Kevin
 *
 */


#include "commonblock.h"
#include <QBrush>

/**
 * @brief CommonBlock::CommonBlock This is the cnostructor for the common blocks present in the game
 * @param parent
 */
CommonBlock::CommonBlock(QGraphicsItem *parent): QGraphicsRectItem(parent){
 setRect(0,0,100,20);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
    points = 10;
    breakPoints=1;
}

/**
 * @brief CommonBlock::getPoints This method returns the value of the points given by the block when its destroyed
 * @return the int value of the points
 */
int CommonBlock::getPoints(){
    return points;
}

/**
 * @brief CommonBlock::getCenter this method returns the center of block.
 * @return the center of the block
 */
double CommonBlock::getCenter()
{
    return x()+rect().width()/2;
}


/**
 * @brief CommonBlock::getBPoints this method returns the amount of hits that the block can take.
 * @return the amount of hits that the block can take.
 */
int CommonBlock::getBPoints(){
    return breakPoints;
}
