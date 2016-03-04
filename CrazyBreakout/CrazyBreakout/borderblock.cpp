/**
 *
 * @author Kevin
 *
 */


#include "borderblock.h"
#include <QBrush>

/**
 * @brief BorderBlock::BorderBlock This is the cnostructir for the border blocks present in the game
 * @param parent
 */
BorderBlock::BorderBlock(QGraphicsItem *parent): QGraphicsRectItem(parent){
    setRect(0,0,100,30);
   QBrush brush;
   brush.setStyle(Qt::SolidPattern);
   brush.setColor(Qt::gray);
   setBrush(brush);
    points = 30;
    breakPoints=1;
}

/**
 * @brief BorderBlock::getPoints This method returns the value of the points given by the block when its destroyed
 * @return the int value of the points
 */
int BorderBlock::getPoints(){
    return points;
}

/**
 * @brief BorderBlock::getCenter this method returns the center of block.
 * @return the center of the block
 */
double BorderBlock::getCenter()
{
    return x()+rect().width()/2;
}

/**
 * @brief BorderBlock::getBPoints this method returns the amount of hits that the block can take.
 * @return the amount of hits that the block can take.
 */
int BorderBlock::getBPoints(){
    return breakPoints;
}
