#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Platform : public QGraphicsPixmapItem {
public:
    Platform(QGraphicsScene* scene, int x, int y);
};

#endif // PLATFORM_H
