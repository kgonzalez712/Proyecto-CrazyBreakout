#ifndef COMMONBLOCK_H
#define COMMONBLOCK_H

#include <QGraphicsRectItem>
#include <block.h>

class CommonBlock: public Block, public QGraphicsRectItem{
public:
    // constructors
    CommonBlock(QGraphicsItem* parent=NULL);
    int getBPoints();
    int getPoints();
    double getCenter();

};

#endif // COMMONBLOCK_H
