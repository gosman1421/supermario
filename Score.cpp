#include "Score.h"
#include <QFont>
#include <QGraphicsScene>
Score::Score(int s, QGraphicsItem * parent):QGraphicsTextItem(parent)
{
    score = s;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Times",16));
    setPos(0,0);
}


void Score::increasescore()
{
    score = score + 10;
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
