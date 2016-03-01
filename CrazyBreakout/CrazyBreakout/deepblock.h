#ifndef DEEPBLOCK_H
#define DEEPBLOCK_H

#include <QGraphicsRectItem>
#include <block.h>

class DeepBlock: public Block, public QGraphicsRectItem{
public:
    // constructors
    DeepBlock(QGraphicsItem* parent=NULL);
    double getCenter();

};

#endif // DEEPBLOCK_H
