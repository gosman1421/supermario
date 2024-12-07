#ifndef GAME_H
#define GAME_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsTextItem>
#include "Health.h"
#include "player.h"
#include "coin.h"
#include "enemy.h"
#include "Score.h"
#include "GameLevel.h"
class Game: public QObject {
    Q_OBJECT

private:

    QGraphicsView* view;
    QTimer* gameTimer;
    Health* health;
    Score* scoreManager;
    player* mainPlayer;
    QList<coin*> coins;
    QList<Enemy*> enemies;
    int score;
    int currentLevel;
    bool shield;

    void loadLevel(int level);
    void initGame();
    //QGraphicsTextItem* levelText;
    QGraphicsPixmapItem* finishLine;
public:
    Game();
    ~Game();
    void displaymainwindow();
    void startGame();
    void restartGame();
    void quitGame();
    void pauseGame();
    void restartLevel();
    void gameOver();
    void nextLevel();
    void checkCollisions();
    void updateHUD();
    QGraphicsScene* scene;
    void simulateMouseClick();

public slots:
    void updateGame();

};

#endif // GAME_H
