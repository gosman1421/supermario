#ifndef HEART_H
#define HEART_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "score.h"
#include "player.h"
#include <QGraphicsItem>

class heart : public QGraphicsPixmapItem {
public:
    heart(QGraphicsScene *scene, Score *scoreManager);

    bool checkCollisionWithPlayer(player *mainplayer);
    void collectheart();
private:
    QGraphicsScene *scene;
    Score *scoreManager;
};

#endif

