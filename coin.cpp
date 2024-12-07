#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
#include "score.h"
#include "player.h"
#include "coin.h"
///C*oin::Coin(QGraphicsScene *scene, QGraphicsTextItem *scoreDisplay)


//////The main function for the coins
////QList<Coin *> coins;
//// for(int i = 0; i < 10; i++){
////    Coin *coin = new Coin(scene, scoreDisplay, score);
////    coin->setPos(i * 100 + 100, 300);
////    coins.append(coin);
////}


coin::coin(QGraphicsScene *scene, Score *scoreManager)
    : scene(scene), scoreManager(scoreManager) {
    setPixmap(QPixmap("C:/Users/Dell/OneDrive/Desktop/clipart4500979.png"));
    setScale(0.05);
    scene->addItem(this);
}

bool coin::checkCollisionWithPlayer(player *mainplayer) {
    if (collidesWithItem(mainplayer)) {
        collectCoin();
        return true;
    }
    return false;
}

void coin::collectCoin() {
    scene->removeItem(this);
    }
