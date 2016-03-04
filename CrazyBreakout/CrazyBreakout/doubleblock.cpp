/**
 *
 * @author Kevin
 *
 */

#include "doubleblock.h"
#include <QBrush>

/**
 * @brief DoubleBlock::DoubleBlock This is the cnostructor for the double blocks present in the game
 * @param parent
 */
DoubleBlock::DoubleBlock(QGraphicsItem *parent)
{
 setRect(0,0,100,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
    points = 15;
    breakPoints=2;
}

/**
 * @brief DoubleBlock::getPoints This method returns the value of the points given by the block when its destroyed
 * @return the int value of the points
 */
int DoubleBlock::getPoints(){
    return points;
}

/**
 * @brief DoubleBlock::getBPoints this method returns the amount of hits that the block can take.
 * @return the amount of hits that the block can take.
 */
int DoubleBlock::getBPoints(){
    return breakPoints;
}

/**
 * @brief DoubleBlock::getCenter this method returns the center of block.
 * @return the center of the block
 */
double DoubleBlock::getCenter()
{
    return x()+rect().width()/2;
}
