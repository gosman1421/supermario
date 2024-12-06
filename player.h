#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
// #include <QGraphicsPixmapItem>
// #include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QSet>
#include <QObject>
#include "Score.h"
#include <QGraphicsItem>
class player : public QMainWindow, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int score;
    int lives;
    int coins;
    int speed;
    bool hasTemporaryAbility;
    bool isjumping;
      // Flag to indicate if the player has a temporary ability
    QSet<int> activeKeys;
    QTimer* movementTimer;

public:
        // player(QWidget *parent = nullptr);
    player(QGraphicsItem* parent = nullptr, QGraphicsScene *scene1 =nullptr);
     QGraphicsScene *scene;
    // Getters
    int getScore() const;
    int getLives() const;
    int getCoins() const;
    bool hasAbility() const;

    // Setters
    void setLives(int newLives);
    void addScore(int points);
    void addCoin();
    void setSpeed(int newSpeed);
    // Abilities
    void activateTemporaryAbility();
    void deactivateTemporaryAbility();

    // Methods for player actions
    void reduceLife();
    bool isAlive() const;

    void moveDown();
    void handleMovement();
protected:
    // Handle keyboard events for player movement
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

signals:
    void lifeChanged(int lives);
    void scoreChanged(int score);
    void coinsChanged(int coins);
    // ~player();
};
#endif // PLAYER_H
