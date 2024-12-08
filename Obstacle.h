#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Obstacle : public QGraphicsPixmapItem {
public:
    Obstacle(QGraphicsScene* scene, int x, int y);
};

#endif // OBSTACLE_H
