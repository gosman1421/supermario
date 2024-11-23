#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "Score.h" 
#include "player.h" 
#include "Enemy.h"
Enemy::Enemy(QGraphicsScene *scene, ObstacleType type, Score *score, int speed)
    : scene(scene), type(type), score(score), speed(speed) {

    setPixmap(QPixmap("EnemyImage Link")); 
    scene->addItem(this);

    setPos(800, 300);  /

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
                score->decrementScore();  
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
