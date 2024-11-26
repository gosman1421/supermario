#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>

class player : public QMainWindow, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int score;              // Current score of the player
    int lives;              // Current lives of the player
    int coins;              // Coins collected by the player
    bool hasTemporaryAbility; // Flag to indicate if the player has a temporary ability
public:
        // player(QWidget *parent = nullptr);
    explicit player(QGraphicsItem* parent = nullptr);

    // Getters
    int getScore() const;
    int getLives() const;
    int getCoins() const;
    bool hasAbility() const;

    // Setters
    void setLives(int newLives);
    void addScore(int points);
    void addCoin();

    // Abilities
    void activateTemporaryAbility();
    void deactivateTemporaryAbility();

    // Methods for player actions
    void reduceLife();
    bool isAlive() const;

protected:
    // Handle keyboard events for player movement
    void keyPressEvent(QKeyEvent* event) override;

signals:
    void lifeChanged(int lives);
    void scoreChanged(int score);
    void coinsChanged(int coins);
    // ~player();
};
#endif // PLAYER_H
