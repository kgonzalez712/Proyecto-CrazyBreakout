#ifndef TRIPLEBLOCK_H
#define TRIPLEBLOCK_H



#include <QGraphicsRectItem>
#include "block.h"

class TripleBlock: public Block, public QGraphicsRectItem{
public:
    // constructors
    TripleBlock(QGraphicsItem* parent=NULL);
    int getBPoints();
    int getPoints();
    double getCenter();

};


#endif // TRIPLEBLOCK_H
