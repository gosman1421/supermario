#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
#include "score.h"
#include "player.h"
#include "coin.h"
///C*oin::Coin(QGraphicsScene *scene, QGraphicsTextItem *scoreDisplay)
//    : scene(scene), scoreDisplay(scoreDisplay) {
//    setPixmap(QPixmap("/Users/ghadasherif/Documents/GitHub/assignment-5-ghadasherif/Code_lib/coin-1.jpeg"));
//    scene->addItem(this);
//}

//void Coin::checkCollisionWithPlayer(QGraphicsPixmapItem *player) {
//    if (collidesWithItem(player)) {
//        collectCoin();
//    }
//}

//void Coin::collectCoin() {
//    scene->removeItem(this);
//    delete this;

//    score.increasescore();
//    scoreDisplay->setPlainText(QString("Score: %1").arg(scoreDisplay->getscore()));
//    //scoreDisplay->setPlainText(QString("Score: %1").arg(score));
//}


//////The main function for the coins
////QList<Coin *> coins;
//// for(int i = 0; i < 10; i++){
////    Coin *coin = new Coin(scene, scoreDisplay, score);
////    coin->setPos(i * 100 + 100, 300);
////    coins.append(coin);
////}

//QTimer *timer = new QTimer();
//QObject::connect(timer, &QTimer::timeout, [=]() {
//    for (Coin *coin : coins) {
//        if (coin) {
//            coin->checkCollisionWithPlayer(player);
//        }
//    }
//});
//timer->start(50);*/

coin::coin(QGraphicsScene *scene, Score *scoreManager)
    : scene(scene), scoreManager(scoreManager) {
    setPixmap(QPixmap("C:/Users/AUC/Downloads/mario_coin.jpg"));
    scene->addItem(this);
}

void coin::checkCollisionWithPlayer(player *mainplayer) {
    if (collidesWithItem(mainplayer)) {
        collectCoin();
    }
}

void coin::collectCoin() {
    scene->removeItem(this);
    delete this;

    scoreManager->increasescore();
}


