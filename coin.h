#ifndef COIN_H
#define COIN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "score.h"
#include "player.h"
#include <QGraphicsItem>
class coin : public QGraphicsPixmapItem {
public:
    coin(QGraphicsScene *scene, Score *scoreManager);

    bool checkCollisionWithPlayer(player *mainplayer);
    void collectCoin();
private:
    QGraphicsScene *scene;
    Score *scoreManager;
};

#endif
