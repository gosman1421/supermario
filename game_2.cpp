#include "game_2.h"
#include "welcomewindow.h"
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <QDebug>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QFont>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QMessageBox>

Game2::Game2() : score(0), currentLevel(1) {
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    scene->clear();
    view->setFixedSize(800, 600);
    view->setSceneRect(0, 0, 2000, 600);

    QPixmap backgroundPixmap("C:/Users/Dell/OneDrive/Desktop/Scene.png");
    QPixmap scaledPixmap = backgroundPixmap.scaled(view->sceneRect().size().toSize(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(scaledPixmap);
    backgroundItem->setPos((view->sceneRect().width() - scaledPixmap.width()) / 2, (view->sceneRect().height() - scaledPixmap.height()) / 2);
    scene->addItem(backgroundItem);

    view->show();

    gameTimer = new QTimer(this);
    health = new Health(100, 3);
    scoreManager = new Score();
    mainPlayer = new player();
    mainPlayer->scene = scene;

    scene->addItem(scoreManager);
    scene->addItem(mainPlayer);
    //simulateMouseClick2();
    scene->addItem(health);
    scene->update();
    connect(mainPlayer, &player::gameOver, this, &Game2::gameOver);

    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &Game2::updateGame);
    gameTimer->start(500);
    initGame();
    shield = false;
}

#include <QGraphicsSceneMouseEvent>
#include <QApplication>

// void Game2::simulateMouseClick2() {
//     QGraphicsSceneMouseEvent pressEvent(QEvent::GraphicsSceneMousePress);
//     pressEvent.setScenePos(mainPlayer->QGraphicsItem::pos());
//     pressEvent.setButton(Qt::LeftButton);
//     pressEvent.setButtons(Qt::LeftButton);
//     pressEvent.setModifiers(Qt::NoModifier);
//     QApplication::sendEvent(mainPlayer, &pressEvent);

//     QGraphicsSceneMouseEvent releaseEvent(QEvent::GraphicsSceneMouseRelease);
//     releaseEvent.setScenePos(mainPlayer->QGraphicsItem::pos());
//     releaseEvent.setButton(Qt::LeftButton);
//     releaseEvent.setButtons(Qt::NoButton);
//     releaseEvent.setModifiers(Qt::NoModifier);
//     QApplication::sendEvent(mainPlayer, &releaseEvent);
// }

Game2::~Game2() {
    delete scene;
    delete view;
    delete gameTimer;
    delete health;
    delete scoreManager;
    delete mainPlayer;
}

void Game2::initGame() {
    loadLevel(currentLevel);
    updateHUD();

    for (int i = 0; i < 5; i++) {
        coin* newCoin = new coin(scene, scoreManager);
        newCoin->setPos(i * 150 + 100, 550);
        coins.append(newCoin);
    }

    Enemy* newEnemy = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 400, 0);
    enemies.append(newEnemy);
    Enemy* newEnemy2 = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 800, 400);
    enemies.append(newEnemy2);
    QGraphicsPixmapItem* finishLine = new QGraphicsPixmapItem(QPixmap("C:/Users/Dell/OneDrive/Desktop/flag.png"));
    finishLine->setPos(1900, 500);
    finishLine->setScale(0.5);
    scene->addItem(finishLine);

    health->setPos(0, 40);
    scene->update();
    this->finishLine = finishLine;
}

QGraphicsTextItem* LLL2;
void Game2::loadLevel(int level) {
    QGraphicsTextItem* levelText = new QGraphicsTextItem(QString("Level %1").arg(level));
    levelText->setPos(800, 0);
    QFont font("Times", 16, QFont::Bold);
    levelText->setFont(font);
    levelText->setDefaultTextColor(Qt::red);
    LLL2 = levelText;
    scene->addItem(LLL2);
}

void Game2::startGame() {
    gameTimer->start(16);
    qDebug() << "Game started!";
}

void Game2::pauseGame() {
    gameTimer->stop();
    qDebug() << "Game paused.";
}

void Game2::restartLevel() {
    health->resetHealth();
    loadLevel(currentLevel);
    qDebug() << "Level restarted.";
}

void Game2::gameOver() {
    gameTimer->stop();
    QMessageBox::critical(nullptr, "Game Over", "Game Over! You have no more lives left.", QMessageBox::Ok);
    welcomewindow* welcome = new welcomewindow();
    welcome->show();

    delete scene;
    delete view;
    delete gameTimer;
    delete health;
    delete scoreManager;
    delete mainPlayer;
    QApplication::quit();
}

void Game2::nextLevel() {
    currentLevel++;
    loadLevel(currentLevel);
}

void Game2::checkCollisions() {
    for (coin* c : coins) {
        if (c->checkCollisionWithPlayer(mainPlayer)) {
            scoreManager->increasescore();
            scene->update();
            coins.removeAll(c);
        }
    }
    for (Enemy* e : enemies) {
        if (e->checkCollisionWithPlayer(mainPlayer) && !shield) {
            health->takeDamage(20);
            shield = true;
            QTimer::singleShot(1000, this, [this]() {
                shield = false;
            });
            scene->update();
        }
    }
}

void Game2::updateHUD() {
    qDebug() << "Score:" << score << "Health:" << health->getCurrentHealth();
}

void Game2::restartGame() {
    health->resetHealth();
    scoreManager->resetscore();
    currentLevel = 1;
    loadLevel(currentLevel);
    mainPlayer->setPos(100, 550);
    for (int i = 0; i < 5; i++) {
        coin* newCoin = new coin(scene, scoreManager);
        newCoin->setPos(i * 150 + 100, 550);
        coins.append(newCoin);
    }
    Enemy* newEnemy = new Enemy(scene, Enemy::Moving, scoreManager, 10, 550, 800, 0);
    enemies.append(newEnemy);
    startGame();
    qDebug() << "Game Restarted!";
}

void Game2::updateGame() {
    view->centerOn(mainPlayer);
    checkCollisions();
    updateHUD();
    if (mainPlayer->collidesWithItem(finishLine)) {
        gameOver();
        return;
    }
    if (health->getCurrentHealth() == 0 && !health->hasLivesLeft()) {
        gameOver();
        return;
    }
    if (health->getCurrentHealth() == 0) {
        health->loseLife();
        QMessageBox::StandardButton reply = QMessageBox::critical(nullptr, "Life Loss", "Lost one life", QMessageBox::Ok);
        if (reply == QMessageBox::Ok) {
            qDebug() << "User acknowledged life loss.";
            welcomewindow* h = new welcomewindow;
            h->show();
            delete view;
            delete gameTimer;
            delete health;
            delete scoreManager;
            delete mainPlayer;
        }
    }
    QPointF sceneTopLeft = view->mapToScene(0, 0);
    health->setPos(sceneTopLeft.x(), sceneTopLeft.y() + 40);
}
