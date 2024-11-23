#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "score.h"   
#include "player.h"  
#include "Coin.h"

Coin::Coin(QGraphicsScene *scene, QGraphicsTextItem *scoreDisplay, int &score)
    : scene(scene), scoreDisplay(scoreDisplay), score(score) {
    setPixmap(QPixmap("C:\Users\AUC\Downloads\mario_coin.jpg"));  
    scene->addItem(this); 
}

void Coin::checkCollisionWithPlayer(QGraphicsPixmapItem *player) {
    if (collidesWithItem(player)) {
        collectCoin();
    }
}

void Coin::collectCoin() {
    scene->removeItem(this);
    delete this;

    score.increaseScore();
    scoreDisplay->setPlainText(QString("Score: %1").arg(score));
}


  //The main function for the coins
QList<Coin *> coins;
for (int i = 0; i < 10; i++) {
    Coin *coin = new Coin(scene, scoreDisplay, score);
    coin->setPos(i * 100 + 100, 300);
    coins.append(coin);
}

QTimer *timer = new QTimer();
QObject::connect(timer, &QTimer::timeout, [=]() {
    for (Coin *coin : coins) {
        if (coin) {
            coin->checkCollisionWithPlayer(player);
        }
    }
});
timer->start(50);



