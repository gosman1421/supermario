#include "Score.h"
#include <QFont>
#include <QGraphicsScene>
Score::Score(QGraphicsItem * parent):QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("Times",16));
    setPos(0,0);
}


void Score::increasescore()
{
    score = score + 30;
    setPlainText(QString("Score: ") + QString::number(score));
}


void Score::decrementscore(){
    score--;
}

int Score::getscore()
{
    return score;
}

void Score::resetscore() {
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
}
