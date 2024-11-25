#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "Score.h"
#include "player.h"
#include "enemy.h"
Enemy::Enemy(QGraphicsScene *scene, ObstacleType type, Score *newscore, int speed)
    : scene(scene), type(type), setscore(newscore), speed(speed) {

    setPixmap(QPixmap("C:/Users/AUC/Downloads/enemy_mario.png"));
    scene->addItem(this);

    setPos(800, 300);

        if (type == Moving) {
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Enemy::move);
        timer->start(50);
    }
}

void Enemy::move() {
    if (type == Moving) {
        setPos(x() - speed, y());

        for (QGraphicsItem *item : collidingItems()) {
            if (item->type() == QGraphicsPixmapItem::Type) {
                setscore->decrementscore();
                scene->removeItem(this);
                delete this;
                return;
            }
        }

        if (x() + pixmap().width() < 0) {
            scene->removeItem(this);
            delete this;
        }
    }
}
