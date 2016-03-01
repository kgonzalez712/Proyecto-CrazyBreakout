#ifndef SURPRISEBLOCK_H
#define SURPRISEBLOCK_H

#include <QGraphicsRectItem>
#include <block.h>

class SurpriseBlock: public Block , public QGraphicsRectItem{
public:
    // constructors
    SurpriseBlock(QGraphicsItem* parent=NULL);
    double getCenter();

};

#endif // SURPRISEBLOCK_H
