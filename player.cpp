#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QApplication>
#include <QGraphicsView>
player::player(QGraphicsItem* parent, QGraphicsScene *scene1)
    : QGraphicsPixmapItem(parent), score(0), lives(3), coins(0), speed(10), hasTemporaryAbility(false), scene(scene1), isjumping(false) {
    setPixmap(QPixmap("C:/Users/AUC/Documents/GitHub/supermario/PngItem_1478513.png"));
    setScale(0.1);
    setPos(0, 525);
    setFlag(QGraphicsItem::ItemIsFocusable);
    this->QGraphicsItem::setFocus();
    //this->setFocus();
    movementTimer = new QTimer(this);
    connect(movementTimer, &QTimer::timeout, this, &player::handleMovement);
    movementTimer->start(30);
    setFlag(QGraphicsItem::ItemIsFocusable);
    QGraphicsItem::setFocus();
    QApplication::instance()->installEventFilter(this);

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

void player::setSpeed(int newSpeed) {
    speed = newSpeed;
}

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

    activeKeys.insert(event->key());

    int x = QGraphicsPixmapItem::x();
    int y = QGraphicsPixmapItem::y();

    if (activeKeys.contains(Qt::Key_Left)) {
        x -= speed;
    }
    if (activeKeys.contains(Qt::Key_Right)) {
        x += speed;
    }
    if (activeKeys.contains(Qt::Key_Up) && !isjumping) {
        y -= 60;
        isjumping = true;
        QTimer::singleShot(500, this, [this]() {
            moveDown();
            isjumping = false;
        });
    }

    setPos(x, y); // Update position
    scene->update();
}

void player::keyReleaseEvent(QKeyEvent* event) {
    activeKeys.remove(event->key());

}


// Function to move the player back down
void player::moveDown() {
    setPos(QGraphicsPixmapItem::x(), QGraphicsPixmapItem::y() + 60); // Move back down
    scene->update();
}

void player::handleMovement() {
    int x = QGraphicsPixmapItem::x();
    int y = QGraphicsPixmapItem::y();

    if (activeKeys.contains(Qt::Key_Left)) {
        x -= speed; // Adjust speed as needed
    }
    if (activeKeys.contains(Qt::Key_Right)) {
        x += speed;
    }

    setPos(x, y); // Update position
    scene->update();
}
