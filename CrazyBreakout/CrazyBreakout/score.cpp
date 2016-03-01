#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("S C O R E : ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("comic",16));
}

void Score::increase(int value){
    score= score + value ;
    setPlainText(QString("S C O R E : ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}
