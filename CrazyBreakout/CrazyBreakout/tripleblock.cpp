/**
 *
 * @author Kevin
 *
 */

#include "tripleblock.h"
#include <QBrush>

/**
 * @brief DoubleBlock::DoubleBlock This is the cnostructor for the double blocks present in the game
 * @param parent
 */
TripleBlock::TripleBlock(QGraphicsItem *parent)
{
    // draw rect
 setRect(0,0,100,45);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
    points = 12;
    breakPoints=3;
}


/**
 * @brief DoubleBlock::getPoints This method returns the value of the points given by the block when its destroyed
 * @return the int value of the points
 */
int TripleBlock::getPoints(){
    return points;
}

/**
 * @brief DoubleBlock::getCenter this method returns the center of block.
 * @return the center of the block
 */
double TripleBlock::getCenter()
{
    return x()+rect().width()/2;
}

/**
 * @brief DoubleBlock::getBPoints this method returns the amount of hits that the block can take.
 * @return the amount of hits that the block can take.
 */
int TripleBlock::getBPoints(){
    return breakPoints;
}
