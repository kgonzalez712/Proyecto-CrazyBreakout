#include "tripleblock.h"
#include <QBrush>

TripleBlock::TripleBlock(QGraphicsItem *parent)
{
    // draw rect
 setRect(0,0,100,35);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
    points = 12;
    breakPoints=3;
}

int TripleBlock::getPoints(){
    return points;
}

double TripleBlock::getCenter()
{
    return x()+rect().width()/2;
}

int TripleBlock::getBPoints(){
    return breakPoints;
}
