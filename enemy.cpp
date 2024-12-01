#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "Score.h"
#include "player.h"
#include "enemy.h"
Enemy::Enemy(QGraphicsScene *scene, ObstacleType type, Score *newscore, int speed)
    : scene(scene), type(type), setscore(newscore), speed(speed) {

    setPixmap(QPixmap("C:/Users/Dell/OneDrive/Desktop/kindpng_3952566.png"));
    setScale(0.1);
    scene->addItem(this);
    setPos(800, 500);

        if (type == Moving) {
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Enemy::move);
        timer->start(50);
    }
        scene->update();
}

void Enemy::move() {
    if (type == Moving) {
        setPos(x() - speed, y());

        // for (QGraphicsItem *item : collidingItems()) {
        //     if (item->type() == QGraphicsPixmapItem::Type) {
        //         setscore->decrementscore();
        //         scene->removeItem(this);
        //         delete this;
        //         return;
        //     }
        // }

        if (x() + pixmap().width() < 0) {
            scene->removeItem(this);
            delete this;
        }
    }
}

bool Enemy::checkCollisionWithPlayer(player *mainplayer) {
    if (collidesWithItem(mainplayer)) {

        return true;
    }
    return false;
}
