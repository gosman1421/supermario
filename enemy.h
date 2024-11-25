#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "Score.h"
#include "player.h"

class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    enum ObstacleType { Static, Moving };


    Enemy(QGraphicsScene *scene, ObstacleType type, Score *setscore, int speed = 0);

private:
    QGraphicsScene *scene;
    ObstacleType type;
    int speed;
    Score * setscore;

private slots:
    void move();

};

#endif
