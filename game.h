#ifndef GAME_H
#define GAME_H
                                //I LOVE CHICKEN SHAWERMA
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsTextItem>
#include "Health.h"
//#include "GameLevel.h"

class Game:public QObject{
    Q_OBJECT

private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    QTimer*gameTimer;
    Health*health;
    int score;
    int currentLevel;

    void initGame();
    void loadLevel (int level);

public:
    Game();
    ~Game();

    void startGame() ;
    void pauseGame();
    void restartLevel();
    void gameOver();
    void nextLevel() ;

    void checkCollisions();
    void updateHUD();

public slots:
    void updateGame() ;
};

#endif
