#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QApplication>
#include <QGraphicsView>
//player::player(QWidget *parent)
//    : QMainWindow(parent)
//{
//}

player::player( QGraphicsItem* parent, QGraphicsScene *scene1)
    : QGraphicsPixmapItem(parent), score(0), lives(3), coins(0), hasTemporaryAbility(false), scene(scene1){
    // Set the player's image ("/Users/ghadasherif/Desktop/CS2/Assignment 6/cs2 assignment 4/cs2 assignment 4/player.png")
    setPixmap(QPixmap("C:/Users/Dell/OneDrive/Desktop/PngItem_1478513.png"));
    setScale(0.1);
    setFlag(QGraphicsItem::ItemIsFocusable);
    //setFocus();
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
        // Jump upward
        setPos(QGraphicsPixmapItem::x(), QGraphicsPixmapItem::y() - 20);

        // Set a QTimer to call a function to bring the player back down
        QTimer::singleShot(1000, this, [this]() {
            moveDown();
        });
    }
    scene->update();
}

// Function to move the player back down
void player::moveDown() {
    setPos(QGraphicsPixmapItem::x(), QGraphicsPixmapItem::y() + 20); // Move back down
    scene->update();
}


//player::player(QWidget *parent)
//    : QMainWindow(parent)
//{
//}

//player::~player()
//{
//}
