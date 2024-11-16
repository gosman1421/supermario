#include "Score.h"
#include <QFont>
#include <QGraphicsScene>
Score::Score(QGraphicsItem * parent):QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("Times",16));
    //QGraphicsScene * scene = new QGraphicsScene();
    //scene->addItem(score);
}

void Score::increasescore()
{
    score++;
}

int Score::getscore()
{
    return score;
}
