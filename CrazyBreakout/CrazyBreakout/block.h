#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>

class Block
{
public:
    Block();
    int getPoints();
    int getBPoints();
protected:
    int points;
    int breakPoints;
};

#endif // BLOCK_H
