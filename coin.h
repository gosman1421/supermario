#ifndef COIN_H
#define COIN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "score.h"
#include "player.h"

class coin : public QGraphicsPixmapItem {
public:
    coin(QGraphicsScene *scene, Score *scoreManager);

    void checkCollisionWithPlayer(player *mainplayer);
    void collectCoin();
private:
    QGraphicsScene *scene;
    Score *scoreManager;
};

#endif

