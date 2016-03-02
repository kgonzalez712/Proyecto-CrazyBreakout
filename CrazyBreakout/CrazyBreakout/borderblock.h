#ifndef BORDERBLOCK_H
#define BORDERBLOCK_H


#include <QGraphicsRectItem>
#include <block.h>

class BorderBlock: public Block, public QGraphicsRectItem{
public:
    // constructors
    BorderBlock(QGraphicsItem* parent=NULL);
    int getBPoints();
    int getPoints();
    double getCenter();

};

#endif // COMMONBLOCK_H
