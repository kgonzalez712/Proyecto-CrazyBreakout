#ifndef BORDERBLOCK_H
#define BORDERBLOCK_H


#include <QGraphicsRectItem>
#include <block.h>

class BorderBlock: public Block, public QGraphicsRectItem{
public:
    BorderBlock(QGraphicsItem* parent=NULL);
    int getBPoints();
    int getPoints();
    double getCenter();

};

#endif // COMMONBLOCK_H
