/**
 *
 * @author Kevin
 *
 */

#include "deepblock.h"
#include <QBrush>

/**
 * @brief DeepBlock::DeepBlock This is the cnostructor for the deep blocks present in the game
 * @param parent
 */
DeepBlock::DeepBlock(QGraphicsItem *parent){
 setRect(0,0,100, 70);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

/**
 * @brief DeepBlock::getCenter this method returns the center of block.
 * @return the center of the block
 */
double DeepBlock::getCenter(){
    return x()+rect().width()/2;
}
