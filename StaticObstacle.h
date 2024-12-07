#ifndef STATICOBSTACLE_H
#define STATICOBSTACLE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class StaticObstacle : public QGraphicsPixmapItem {
public:
    StaticObstacle(QGraphicsScene* scene, int x, int y, const QString& imagePath);
};

#endif
