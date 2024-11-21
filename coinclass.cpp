class Coin : public QGraphicsPixmapItem {
public:
    Coin(QGraphicsScene *scene, QGraphicsTextItem *scoreDisplay, int &score)
        : scene(scene), scoreDisplay(scoreDisplay), score(score) {
        
        setPixmap(QPixmap("Image Link")); // image link to choose it in the meeting
        scene->addItem(this); 
    }

      void checkCollisionWithPlayer(QGraphicsPixmapItem *player) {
        if (collidesWithItem(player)) {
            collectCoin();
        }
    }

private:
    QGraphicsScene *scene;
    QGraphicsTextItem *scoreDisplay;
    Score &score;

      void collectCoin() {
        scene->removeItem(this);
        delete this;

     
        score.increasescore();
        scoreDisplay->setPlainText(QString("Score: %1").arg(score));
    }
};






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



