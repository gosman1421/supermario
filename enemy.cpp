#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "Score.h"
#include "player.h"
#include "enemy.h"
Enemy::Enemy(QGraphicsScene *scene, ObstacleType type, Score *newscore, int speed, int h, int start, int end)
    : scene(scene), type(type), speed(speed), setscore(newscore), height(h), starting(start), ending(end){

    setPixmap(QPixmap("C:/Users/Dell/OneDrive/Desktop/super-mario-bros-goomba-8-bit-0c7e43b6db7b44d66a6308e888bbc222.png"));
    setScale(0.05);
    scene->addItem(this);
    setPos(starting, height);
    scene->update();

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


        if (x() <= ending || x() >= starting) {
            //this->setPos(starting, height);
            // scene->removeItem(this);
            // delete this;
            speed -= 2*speed;
        }
    }
}

bool Enemy::checkCollisionWithPlayer(player *mainplayer) {
    if (collidesWithItem(mainplayer)) {

        return true;
    }
    return false;
}
