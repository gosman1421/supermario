#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
//player::player(QWidget *parent)
//    : QMainWindow(parent)
//{
//}

player::player( QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent), score(0), lives(3), coins(0), hasTemporaryAbility(false) {
    // Set the player's image ("/Users/ghadasherif/Desktop/CS2/Assignment 6/cs2 assignment 4/cs2 assignment 4/player.png")
    setPixmap(QPixmap("C:/Users/AUC/Downloads/png-clipart-mario-mario.png"));
}
//"/Users/ghadasherif/Desktop/CS2/Assignment 6/cs2 assignment 4/cs2 assignment 4/player.png"
// Getters
int player::getScore() const { return score; }
int player::getLives() const { return lives; }
int player::getCoins() const { return coins; }
bool player::hasAbility() const { return hasTemporaryAbility; }

// Setters
void player::setLives(int newLives) {
    lives = newLives;
    emit lifeChanged(lives); // Notify the UI or game logic
}

void player::addScore(int points) {
    score += points;
    emit scoreChanged(score);
}
//
void player::addCoin() {
    coins += 1;
    emit coinsChanged(coins);
}

// Abilities
void player::activateTemporaryAbility() {
    hasTemporaryAbility = true;
}

void player::deactivateTemporaryAbility() {
    hasTemporaryAbility = false;
}

// Reduce player's life
void player::reduceLife() {
    if (lives > 0) {
        lives -= 1;
        emit lifeChanged(lives);
    }
}

// Check if the player is alive
bool player::isAlive() const {
    return lives > 0;
}

void player::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Left) {
        setPos(QGraphicsPixmapItem::x() - 10, QGraphicsPixmapItem::y()); // Move left
    } else if (event->key() == Qt::Key_Right) {
        setPos(QGraphicsPixmapItem::x() + 10, QGraphicsPixmapItem::y()); // Move right
    } else if (event->key() == Qt::Key_Up) {
        setPos(QGraphicsPixmapItem::x(), QGraphicsPixmapItem::y() - 20); // Jump
    } else if (event->key() == Qt::Key_Down) {
        setPos(QGraphicsPixmapItem::x(), QGraphicsPixmapItem::y() + 10); // Move down
    }
}

//player::player(QWidget *parent)
//    : QMainWindow(parent)
//{
//}

//player::~player()
//{
//}

