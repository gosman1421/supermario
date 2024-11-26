#include "game.h"
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <QDebug>
#include <QTimer>
#include <QImage>
#include <QBrush>
Game::Game(): score(0), currentLevel(1) {
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    view->setBackgroundBrush(QBrush(QImage("C:/Users/Dell/OneDrive/Desktop/rb_302.png")));
    view->setFixedSize(800, 600);
    view->show();
    gameTimer = new QTimer(this);
    health = new Health(100, 3);
    scoreManager = new Score();
    mainPlayer = new player();
    mainPlayer->scene = scene;
    scene->addItem(scoreManager);
    scene->update();
    scene->addItem(mainPlayer);
    scene->update();
    //connect(gameTimer, &QTimer::timeout, this, &Game::updateGame);
    initGame();
}

Game::~Game() {
    delete scene;
    delete view;
    delete gameTimer;
    delete health;
    delete scoreManager;
    delete mainPlayer;
}

void Game::initGame() {
    loadLevel(currentLevel);
    updateHUD();

    for (int i = 0; i < 5; i++) {
        coin* newCoin = new coin(scene, scoreManager);
        newCoin->setPos(i * 150 + 100, 300);
        coins.append(newCoin);
    }

    Enemy* newEnemy = new Enemy(scene, Enemy::Moving, scoreManager, 2);
    enemies.append(newEnemy);
    scene->update();
}

void Game::loadLevel(int level) {
    //scene->clear();
    QGraphicsTextItem* levelText = new QGraphicsTextItem(QString("Level %1").arg(level));
    levelText->setPos(700,-200);
    QFont font("Times", 16, QFont::Bold);
    levelText->setFont(font);
    levelText->setDefaultTextColor(Qt::red);
    scene->addItem(levelText);
}

void Game::startGame() {
    gameTimer->start(16);
    qDebug() << "Game started!";
}

void Game::pauseGame() {
    gameTimer->stop();
    qDebug() << "Game paused.";
}

void Game::restartLevel() {
    health->resetHealth();
    loadLevel(currentLevel);
    qDebug() << "Level restarted.";
}

void Game::gameOver() {
    qDebug() << "Game Over!";
    gameTimer->stop();
}

void Game::nextLevel() {
    currentLevel++;
    loadLevel(currentLevel);
}

void Game::checkCollisions() {
    for (coin* c : coins) {
        c->checkCollisionWithPlayer(mainPlayer);
    }
    //for (Enemy* e : enemies) {
    //  e->move();
    //}
}

void Game::updateHUD() {
    qDebug() << "Score:" << score << "Health:" << health->getCurrentHealth();
}

void Game::updateGame() {
    checkCollisions();
    updateHUD();
}
