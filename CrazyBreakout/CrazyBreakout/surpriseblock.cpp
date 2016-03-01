#include "surpriseblock.h"
#include <QBrush>

SurpriseBlock::SurpriseBlock(QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw rect
 setRect(0,0,100,40);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
    points = 10;
    breakPoints=1;
}

double SurpriseBlock::getCenter()
{
    return x()+rect().width()/2;
}

