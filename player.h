#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QSet>
#include "Platform.h"

class player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int score;              // Current score of the player
    int lives;              // Current lives of the player
    int coins;              // Coins collected by the player
    bool hasTemporaryAbility;
    bool isjumping;
    bool isFalling;         // New flag to indicate if the player is falling
    int speed;
    QSet<int> activeKeys;
    QTimer* movementTimer;
public:
    // Constructor for the player class, with scene and parent item parameters
    player(QGraphicsItem* parent = nullptr, QGraphicsScene *scene1 = nullptr);
    QGraphicsScene* scene;
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

    // Movement functions
    void moveLeft();
    void moveRight();
    void jump();
    void fall();

protected:
    // Handle keyboard events for player movement
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

signals:
    // Signals for game state changes
    void lifeChanged(int lives);
    void scoreChanged(int score);
    void coinsChanged(int coins);
    void gameOver();
};

#endif // PLAYER_H
