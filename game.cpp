#include "game.h"
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
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
Game::Game() : score(0), currentLevel(1) {
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    scene->clear();
    //displaymainwindow();

    // Set the view's fixed size
    view->setFixedSize(800, 600);
    view->setSceneRect(0, 0, 2000, 600);

    QPixmap backgroundPixmap("C:/Users/Dell/OneDrive/Desktop/Scene.png");

    QPixmap scaledPixmap = backgroundPixmap.scaled(view->sceneRect().size().toSize(),
                                                   Qt::KeepAspectRatioByExpanding,
                                                   Qt::SmoothTransformation);
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(scaledPixmap);
    backgroundItem->setPos((view->sceneRect().width() - scaledPixmap.width()) / 2,
                           (view->sceneRect().height() - scaledPixmap.height()) / 2);
    scene->addItem(backgroundItem);

    view->show();

    gameTimer = new QTimer(this);
    health = new Health(100, 3);
    scoreManager = new Score();
    mainPlayer = new player();
    mainPlayer->scene = scene;
    scene->addItem(scoreManager);
    scene->addItem(mainPlayer);
    simulateMouseClick();
    scene->addItem(health);

    scene->update();
    connect(mainPlayer, &player::gameOver, this, &Game::gameOver);
    gameTimer = new QTimer(this);

    connect(gameTimer, &QTimer::timeout, this, &Game::updateGame);

    gameTimer->start(500);
    initGame();
    shield = false;
}

void Game::simulateMouseClick() {
    QGraphicsSceneMouseEvent pressEvent(QEvent::GraphicsSceneMousePress);
    pressEvent.setScenePos(mainPlayer->QGraphicsItem::pos());
    pressEvent.setButton(Qt::LeftButton);
    pressEvent.setButtons(Qt::LeftButton);
    pressEvent.setModifiers(Qt::NoModifier);

    QApplication::sendEvent(mainPlayer, &pressEvent);

    QGraphicsSceneMouseEvent releaseEvent(QEvent::GraphicsSceneMouseRelease);
    releaseEvent.setScenePos(mainPlayer->QGraphicsItem::pos());
    releaseEvent.setButton(Qt::LeftButton);
    releaseEvent.setButtons(Qt::NoButton);
    releaseEvent.setModifiers(Qt::NoModifier);

    QApplication::sendEvent(mainPlayer, &releaseEvent);
}

// Game::Game(): score(0), currentLevel(1) {
//     scene = new QGraphicsScene();
//     view = new QGraphicsView(scene);
//     view->setBackgroundBrush(QBrush(QImage("C:/Users/Dell/OneDrive/Desktop/Scene.png")));
//     view->setFixedSize(800, 600);
//     view->show();
//     gameTimer = new QTimer(this);
//     health = new Health(100, 3);
//     scoreManager = new Score();
//     mainPlayer = new player();
//     mainPlayer->scene = scene;
//     scene->addItem(scoreManager);
//     scene->update();
//     scene->addItem(mainPlayer);
//     scene->update();
//     //connect(gameTimer, &QTimer::timeout, this, &Game::updateGame);
//     initGame();
// }

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

    for (int i = 0; i < 10; i++) {
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
QGraphicsTextItem* LLL;
void Game::loadLevel(int level) {
    QGraphicsTextItem* levelText = new QGraphicsTextItem(QString("Level %1").arg(level));
    levelText->setPos(700, 0);
    QFont font("Times", 16, QFont::Bold);
    levelText->setFont(font);
    levelText->setDefaultTextColor(Qt::red);
    //scene->addItem(levelText);
    LLL = levelText;
    scene->addItem(LLL);
}

void Game::startGame(){
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
    gameTimer->stop();

    QMessageBox::critical(
        nullptr,
        "Game Over",
        "Game Over! You have no more lives left.",
        QMessageBox::Ok
        );

    welcomewindow* welcome = new welcomewindow();
    welcome->show();

    delete scene;
    delete view;
    delete gameTimer;
    delete health;
    delete scoreManager;
    delete mainPlayer;

    QApplication::quit();
    //    qDebug() << "Game Over!";
    //    gameTimer->stop();
}

void Game::nextLevel() {
    currentLevel++;
    loadLevel(currentLevel);
}

void Game::checkCollisions() {
    for (coin* c : coins) {
        if (c->checkCollisionWithPlayer(mainPlayer)){
            //delete c;

            scoreManager ->increasescore();
            scene ->update();
            coins.removeAll(c);
        }
    }
    for (Enemy* e : enemies) {
        if (e->checkCollisionWithPlayer(mainPlayer) && !shield){
            health->takeDamage(20);
            shield = true;
            QTimer::singleShot(1000, this, [this]() {
                shield = false;
            });
            scene ->update();

        }
    }
}
/*void Game::displaymainwindow(){
    QGraphicsTextItem* titletext= new QGraphicsTextItem(QString( "Bassel Shoeib"));
        QFont titleFont("Mario", 50);
    titletext->setFont(titleFont);
        int txpos= this->width()/2-titletext->boundingRect().width()/2;
        int typos= 150;
        titletext->setPos(txpos, typos);
        scene->addItem(titletext);

        mainwindow* playwindow= new mainwindow(QString("PLAY"));
        int bxpos= this->width()/2-playwindow->boundingRect().width()/2;
        int bypos= 275;
        playwindow->setPos(bxpos, bypos);
        connect(playwindow, SIGNAL(clicked()), this, SLOT(startGame()));
        scene->addItem(playwindow);

        mainwindow* quitwindow= new mainwindow(QString("QUIT"));
        int qxpos= this->width()/2-quitwindow->boundingRect().width()/2;
        int qypos= 350;
        quitwindow->setPos(qxpos, qypos);
        connect(quitwindow, SIGNAL(clicked()), this, SLOT(startGame()));
        scene->addItem(quitwindow);


}*/

void Game::updateHUD() {
    qDebug() << "Score:" << score << "Health:" << health->getCurrentHealth();

}

void Game::restartGame() {
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



void Game::updateGame() {
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
    if (health->getCurrentHealth() == 0){
        health->loseLife();
        QMessageBox::StandardButton reply = QMessageBox::critical(
            nullptr,
            "Life Loss",
            "Lost one life",
            QMessageBox::Ok
            );

        if (reply == QMessageBox::Ok) {
            qDebug() << "User acknowledged life loss.";
            welcomewindow* h= new welcomewindow;
            h->show();
            //delete scene;
            delete view;
            delete gameTimer;
            delete health;
            delete scoreManager;
            delete mainPlayer;

        }
    }
    // QPointF sceneCenter(view->sceneRect().center());

    // // Get the mainPlayer's position
    // QPointF playerPos = mainPlayer->scenePos();

    // // Calculate the offset needed to center the main player
    // QPointF offset = sceneCenter - playerPos;

    // health->setPos(health->pos() + offset);
    // scoreManager->setPos(scoreManager->pos() + offset);
    QPointF sceneTopLeft = view->mapToScene(0, 0);

    health->setPos(sceneTopLeft.x(), sceneTopLeft.y() +40);
    scoreManager->setPos(sceneTopLeft.x(), sceneTopLeft.y());
    LLL->setPos(sceneTopLeft.x() + 650, sceneTopLeft.y());
}

void Game::quitGame() {
    QMessageBox::StandardButton response = QMessageBox::question(
        view, "Quit Game",
        "Are you sure you want to quit the game?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (response == QMessageBox::Yes) {

        qDebug() << "Quitting the game...";
        QApplication::quit();
    } else {
        mainPlayer->setFlag(QGraphicsItem::ItemIsFocusable);
        mainPlayer->QGraphicsItem::setFocus();

        qDebug() << "Quit game cancelled by user.";
    }
}
