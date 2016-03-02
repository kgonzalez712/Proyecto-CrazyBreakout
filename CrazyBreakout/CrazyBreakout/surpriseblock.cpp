/**
 *
 * @author Kevin
 *
 */

#include "surpriseblock.h"
#include <QBrush>

/**
 * @brief SurpriseBlock::SurpriseBlock This is the cnostructor for the common blocks present in the game
 * @param parent
 */
SurpriseBlock::SurpriseBlock(QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw rect
 setRect(0,0,100,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

/**
 * @brief SurpriseBlock::getCenter this method returns the center of block.
 * @return the center of the block
 */
double SurpriseBlock::getCenter()
{
    return x()+rect().width()/2;
}

