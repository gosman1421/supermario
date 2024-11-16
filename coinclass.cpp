#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    
    enum ObstacleType { Static, Moving };

    Enemy(QGraphicsScene *scene, ObstacleType type, int speed = 0) 
        : scene(scene), type(type), speed(speed) {
        
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

private slots:
    void move() {
        if (type == Moving) {
            
            setPos(x() - speed, y());

            
            if (x() + pixmap().width() < 0) {
                scene->removeItem(this);
                delete this;
            }
        }
    }
};
