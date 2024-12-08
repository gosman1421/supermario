#include "Obstacle.h"

Obstacle::Obstacle(QGraphicsScene* scene,int x, int y){
    setPixmap(QPixmap("C:/Users/AUC/Documents/GitHub/supermario/obstacle1.png"));
    setScale(0.5);
    setPos(x,y);
    scene->addItem(this);
}
