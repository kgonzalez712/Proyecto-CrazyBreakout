#include "doubleblock.h"
#include <QBrush>

DoubleBlock::DoubleBlock(QGraphicsItem *parent)
{
    // draw rect
 setRect(0,0,100,20);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
    points = 15;
    breakPoints=2;
}

int DoubleBlock::getPoints(){
    return points;
}

int DoubleBlock::getBPoints(){
    return breakPoints;
}


double DoubleBlock::getCenter()
{
    return x()+rect().width()/2;
}
