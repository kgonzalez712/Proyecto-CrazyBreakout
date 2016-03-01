#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "commonblock.h"
#include "doubleblock.h"
#include "tripleblock.h"
#include "deepblock.h"
#include "surpriseblock.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    CommonBlock *cblock;
    DoubleBlock *dblock;
    TripleBlock *tblock;
    DeepBlock *dpblock;
    SurpriseBlock  *sblock;

};

#endif // GAME_H
