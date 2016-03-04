#ifndef DOUBLEBLOCK_H
#define DOUBLEBLOCK_H


#include <QGraphicsRectItem>
#include "block.h"

class DoubleBlock: public Block, public QGraphicsRectItem{
public:
    DoubleBlock(QGraphicsItem* parent=NULL);
    int getBPoints();
    int getPoints();
    double getCenter();

};

#endif // DOUBLEBLOCK_H
