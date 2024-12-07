#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
#include "score.h"
#include "player.h"
#include "heart.h"
#include "health.h"


heart::heart(QGraphicsScene *scene, Score *scoreManager)
    : scene(scene), scoreManager(scoreManager) {
    setPixmap(QPixmap("C:/Users/AUC/Downloads/newheart.png"));
    setScale(0.05);
    scene->addItem(this);
}

bool heart::checkCollisionWithPlayer(player *mainplayer) {
    if (collidesWithItem(mainplayer)) {
        collectheart();
        return true;
    }
    return false;
}

void heart::collectheart() {

    scene->removeItem(this);
}
