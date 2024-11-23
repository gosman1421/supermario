#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "Score.h"  

class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    enum ObstacleType { Static, Moving };

    Enemy(QGraphicsScene *scene, ObstacleType type, Score *score, int speed = 0) 
        : scene(scene), type(type), score(score), speed(speed) {
        
        setPixmap(QPixmap("EnemyImage Link"));
        scene->addItem(this);

        setPos(800, 300); 

        if (type == Moving) {
            QTimer *timer = new QTimer(this);
            connect(timer, &QTimer::timeout, this, &Enemy::move);
            timer->start(50); 
        }
    }

private:
    QGraphicsScene *scene;
    ObstacleType type;
    int speed; 
    Score *score; 

private slots:
    void move() {
        if (type == Moving) {
            setPos(x() - speed, y());

            
            for (QGraphicsItem *item : collidingItems()) {
                if (item->type() == QGraphicsPixmapItem::Type 
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
};
