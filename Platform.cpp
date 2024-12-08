#include "Platform.h"

Platform::Platform(QGraphicsScene* scene, int x, int y) {
    setPixmap(QPixmap("C:/Users/AUC/Documents/GitHub/supermario/grass-platform-for-8-bit-games-icon-in-pixel-art-style-vector (1).png"));
    setScale(0.1); // Adjust size if needed
    setPos(x, y);
    scene->addItem(this);
}


