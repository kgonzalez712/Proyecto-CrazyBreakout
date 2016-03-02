/**
 *
 * @author Kevin
 *
 */

#include "score.h"
#include <QFont>

/**
 * @brief Score::Score This is the class constructor for the object that will keep track of the player's score
 * @param parent
 */
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("S C O R E : ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("comic",16));
}

/**
 * @brief Score::increase this method increases the value of the player's score each time a block is destroyed
 * @param value
 */
void Score::increase(int value){
    score= score + value ;
    setPlainText(QString("S C O R E : ") + QString::number(score)); // Score: 1
}

/**
 * @brief Score::getScore this methods shows the value that holds the score
 * @return the value of the score
 */
int Score::getScore(){
    return score;
}
