#ifndef COIN_H
#define COIN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "score.h"   
#include "player.h"  

class Coin : public QGraphicsPixmapItem {
public:
    Coin(QGraphicsScene *scene, QGraphicsTextItem *scoreDisplay, int &score);
    void checkCollisionWithPlayer(QGraphicsPixmapItem *player);

private:
    QGraphicsScene *scene;
    QGraphicsTextItem *scoreDisplay;
    Score &score;

    void collectCoin();
};

#endif 
