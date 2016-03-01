#include "deepblock.h"
#include <QBrush>

DeepBlock::DeepBlock(QGraphicsItem *parent){
    // draw rect
 setRect(0,0,100,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);
}

double DeepBlock::getCenter(){
    return x()+rect().width()/2;
}
