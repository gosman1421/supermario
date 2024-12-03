#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "Score.h"
#include <QGraphicsItem>
#include "player.h"
class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    enum ObstacleType { Static, Moving };

    Enemy(QGraphicsScene *scene, ObstacleType type, Score *setscore, int speed = 0, int height = 0, int starting = 0, int ending = 0);
    bool checkCollisionWithPlayer(player *mainplayer);

private:
    QGraphicsScene *scene;
    ObstacleType type;
    int speed;
    Score * setscore;
    int height;
    int starting;
    int ending;

private slots:
    void move();
};

#endif
