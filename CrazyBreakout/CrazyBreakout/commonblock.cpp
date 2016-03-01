#include "commonblock.h"
#include <QBrush>

CommonBlock::CommonBlock(QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw rect
 setRect(0,0,100,10);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
    points = 10;
    breakPoints=1;
}

int CommonBlock::getPoints(){
    return points;
}

double CommonBlock::getCenter()
{
    return x()+rect().width()/2;
}

int CommonBlock::getBPoints(){
    return breakPoints;
}
