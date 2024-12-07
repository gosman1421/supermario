#include "StaticObstacle.h"

StaticObstacle::StaticObstacle(QGraphicsScene* scene, int x, int y, const QString& imagePath) {
    setPixmap(QPixmap(imagePath));
    setPos(x, y);
    setScale(0.1);
    scene->addItem(this);
}
