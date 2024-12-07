#include "game.h"
#include "welcomewindow.h"
#include "updatewindow.h"
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
#include "levelcomplete.h"
#include "heart.h"
#include "QRandomGenerator"


Game::Game(int l, int r, int n) : score(n), currentLevel(r) {
    // Create the scene and view

    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    scene->clear();
    //displaymainwindow();
    level= r;
    scor= n;

    // Set the view's fixed size
    view->setFixedSize(800, 600);
    view->setSceneRect(0, 0, 2000, 600); // Match scene dimensions to the view


    // Load the background image
    QPixmap backgroundPixmap("C:/Users/AUC/Downloads/background.jpg");


    // Scale the background to fit the scene's size
    QPixmap scaledPixmap = backgroundPixmap.scaled(view->sceneRect().size().toSize(),
                                                   Qt::KeepAspectRatioByExpanding,
                                                   Qt::SmoothTransformation);

    // Add the background image as a QGraphicsPixmapItem
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(scaledPixmap);

    // Center the background item in the scene
    backgroundItem->setPos((view->sceneRect().width() - scaledPixmap.width()) / 2,
                           (view->sceneRect().height() - scaledPixmap.height()) / 2);
    scene->addItem(backgroundItem);

    // Show the view
    view->show();

    // Initialize game elements
    lives= l;
    gameTimer = new QTimer(this);
    health = new Health(100, l);
    scoreManager = new Score(n);
    mainPlayer = new player();
    mainPlayer->setFlag(QGraphicsItem::ItemIsFocusable);
    mainPlayer->QGraphicsItem::setFocus();
    mainPlayer->scene = scene;

    // Add game elements to the scene
    scene->addItem(scoreManager);
    scene->addItem(mainPlayer);
    simulateMouseClick();
    scene->addItem(health);
    // Update the scene
    scene->update();

    // Connect game timer if needed
    // connect(gameTimer, &QTimer::timeout, this, &Game::updateGame);
    gameTimer = new QTimer(this);

    // Connect the timer's timeout signal to the updateGame method
    connect(gameTimer, &QTimer::timeout, this, &Game::updateGame);

    // Set the timer to trigger every 500 milliseconds (0.5 seconds)
    gameTimer->start(500);
    // Initialize the game
    initGame();
    shield = false;
}

#include <QGraphicsSceneMouseEvent>
#include <QApplication>

void Game::simulateMouseClick() {
    // Create a QGraphicsSceneMouseEvent for the mouse press
    QGraphicsSceneMouseEvent pressEvent(QEvent::GraphicsSceneMousePress);
    pressEvent.setScenePos(mainPlayer->QGraphicsItem::pos());  // Get position of mainPlayer (QGraphicsItem)
    pressEvent.setButton(Qt::LeftButton);       // Specify the left mouse button
    pressEvent.setButtons(Qt::LeftButton);      // Indicate which buttons are pressed
    pressEvent.setModifiers(Qt::NoModifier);    // No keyboard modifiers

    // Send the mouse press event to the player
    QApplication::sendEvent(mainPlayer, &pressEvent);

    // Create a QGraphicsSceneMouseEvent for the mouse release
    QGraphicsSceneMouseEvent releaseEvent(QEvent::GraphicsSceneMouseRelease);
    releaseEvent.setScenePos(mainPlayer->QGraphicsItem::pos());  // Get position of mainPlayer (QGraphicsItem)
    releaseEvent.setButton(Qt::LeftButton);       // Specify the left mouse button
    releaseEvent.setButtons(Qt::NoButton);       // No buttons pressed
    releaseEvent.setModifiers(Qt::NoModifier);   // No keyboard modifiers

    // Send the mouse release event to the player
    QApplication::sendEvent(mainPlayer, &releaseEvent);
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
    if(currentLevel== 1){

    for (int i = 0; i < 10; i++) {
        coin* newCoin = new coin(scene, scoreManager);
        if(i%2==0){
        newCoin->setPos(i * 150 + 100, 550);
        coins.append(newCoin);
    }
        else{
            newCoin->setPos(i * 250 + 200, 500);
            coins.append(newCoin);
    }


    Enemy* newEnemy = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 1990, 0);
    enemies.append(newEnemy);
    health->setPos(0, 40);
    scene->update();
}
    }
    else if(currentLevel== 2){

        for (int i = 0; i < 8; i++) {
            coin* newCoin = new coin(scene, scoreManager);
            if(i%2==0){
                newCoin->setPos(i * 150 + 100, 550);
                coins.append(newCoin);
            }
            else{
                newCoin->setPos(i * 250 + 150, 500);
                coins.append(newCoin);
            }


        Enemy* newEnemy = new Enemy(scene, Enemy::Moving, scoreManager, 15, 560, 800, 0);
        enemies.append(newEnemy);
        Enemy* newEnemy2 = new Enemy(scene, Enemy::Moving, scoreManager, 15, 560, 1990, 900);
        enemies.append(newEnemy2);
        health->setPos(0, 40);
        scene->update();
    }
    }
    else if(currentLevel== 3){

        for (int i = 0; i < 7; i++) {
            coin* newCoin = new coin(scene, scoreManager);
            if(i%2==0){
                newCoin->setPos(i * 200 + 100, 550);
                coins.append(newCoin);
            }
            else{
                newCoin->setPos(i * 300 + 150, 500);
                coins.append(newCoin);
            }


    Enemy* newEnemy = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 650, 0);
    enemies.append(newEnemy);
    Enemy* newEnemy2 = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 1200, 700);
    enemies.append(newEnemy2);
    Enemy* newEnemy3 = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 1990,1250);
    enemies.append(newEnemy3);
    /*heart* newheart = new heart(scene, scoreManager);
    newheart->setPos(1600, 550);
    hearts.append(newheart);*/

    heart* newheart = new heart(scene, scoreManager);
    newheart->setPos(1250, 500);
    hearts.append(newheart);
    health->setPos(0, 40);
    scene->update();
}
    }
    else if(currentLevel== 4){

        for (int i = 0; i < 6; i++) {
            coin* newCoin = new coin(scene, scoreManager);
            if(i%2==0){
                newCoin->setPos(i * 150 + 100, 550);
                coins.append(newCoin);
            }
            else{
                newCoin->setPos(i * 250 + 150, 500);
                coins.append(newCoin);
            }


        Enemy* newEnemy = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 400, 0);
        enemies.append(newEnemy);
        Enemy* newEnemy2 = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 800, 450);
        enemies.append(newEnemy2);
        Enemy* newEnemy3 = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 1300, 850);
        enemies.append(newEnemy3);
        Enemy* newEnemy4 = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 1900, 1350);
        enemies.append(newEnemy4);
        health->setPos(0, 40);
        scene->update();
    }
    }
    else if(currentLevel== 5){

        for (int i = 0; i < 5; i++) {
            coin* newCoin = new coin(scene, scoreManager);
            if(i%2==0){
                newCoin->setPos(i * 150 + 100, 550);
                coins.append(newCoin);
            }
            else{
                newCoin->setPos(i * 250 + 150, 500);
                coins.append(newCoin);
            }


    Enemy* newEnemy = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 350, 0);
    enemies.append(newEnemy);
    Enemy* newEnemy2 = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 800, 350);
    enemies.append(newEnemy2);
    Enemy* newEnemy3 = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 1200, 850);
    enemies.append(newEnemy3);
    Enemy* newEnemy4 = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 1650, 1300);
    enemies.append(newEnemy4);
    Enemy* newEnemy5 = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 1993, 1700);
    enemies.append(newEnemy5);
    health->setPos(0, 40);
    scene->update();
}
}
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
    qDebug() << "Game Over!";
    gameTimer->stop();
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

    for (heart* h : hearts) {
        if (h->checkCollisionWithPlayer(mainPlayer)){

            health->heal(20);
            scene ->update();
            hearts.removeAll(h);
        }
}
}

void Game::updateHUD() {
    qDebug() << "Score:" << scoreManager->getscore() << "Health:" << health->getCurrentHealth();

}

void Game::restartGame() {
    // Stop the game timer

        // Reset health and score to initial values
        health->resetHealth();
        scoreManager->resetscore();

        // Reset the level to 1
        currentLevel = 1;
        loadLevel(currentLevel);  // Load the first level

        // Reset player's position to the initial starting position
        mainPlayer->setPos(100, 550);  // Assume initial position is (100, 550)

        // Clear and re-add coins and enemies (or reset their positions)
        // Reinitialize coins and enemies
        for (int i = 0; i < 5; i++) {
            coin* newCoin = new coin(scene, scoreManager);
            newCoin->setPos(i * 150 + 100, 550); // Position the coins
            coins.append(newCoin);
        }

        Enemy* newEnemy = new Enemy(scene, Enemy::Moving, scoreManager, 10, 550, 800, 0);
        enemies.append(newEnemy);

        // Start the game timer
        startGame();

        qDebug() << "Game Restarted!";
    }



void Game::updateGame() {
    view->centerOn(mainPlayer);
    checkCollisions();
    updateHUD();
    if(health->getCurrentHealth() !=0 && mainPlayer->QGraphicsPixmapItem::x()>=1995){
        if(level<=4){
            level++;
            levelcomplete* f= new levelcomplete(level, scoreManager->getscore());
            f->show();
            delete view;
            delete gameTimer;
            delete health;
            delete scoreManager;
            delete mainPlayer;
        }
        else{
            QMessageBox::StandardButton reply = QMessageBox::information(
                nullptr,
                "Winning",
                "Congratulations!!! You completed the game. Would you like to go to the main menu?",
                QMessageBox::Ok
                );

            if (reply == QMessageBox::Ok) {
                qDebug() << "User acknowledged life loss.";
                welcomewindow* r= new welcomewindow();
                r->show();
                //delete scene;
                delete view;
                delete gameTimer;
                delete health;
                delete scoreManager;
                delete mainPlayer;

            }
        }


    }

    else if (health->getCurrentHealth() == 0){
        if(health->getCurrentLives()==1){
            QMessageBox::StandardButton reply = QMessageBox::critical(
                nullptr,
                "Life Loss",
                "Lost All Lives. Go Back to Main Menu",
                QMessageBox::Ok
                );

            if (reply == QMessageBox::Ok) {
                qDebug() << "User acknowledged life loss.";
                welcomewindow* r= new welcomewindow();
                r->show();
                //delete scene;
                delete view;
                delete gameTimer;
                delete health;
                delete scoreManager;
                delete mainPlayer;

            }
        }
    else{Health* newhealth= new Health(100,health->getCurrentHealth()-1);
        health= newhealth;
        QMessageBox::StandardButton reply = QMessageBox::critical(
            nullptr,
            "Life Loss",
            "Lost one life",
            QMessageBox::Ok
            );

        if (reply == QMessageBox::Ok) {
            qDebug() << "User acknowledged life loss.";
            updatewindow* h= new updatewindow(lives-1, level);
            h->show();
            //delete scene;
            delete view;
            delete gameTimer;
            delete health;
            delete scoreManager;
            delete mainPlayer;

        }
    }
    }

    QPointF sceneTopLeft = view->mapToScene(0, 0);

    // Add some padding (e.g., 10px from the top and left)
    health->setPos(sceneTopLeft.x(), sceneTopLeft.y() +40);
    scoreManager->setPos(sceneTopLeft.x(), sceneTopLeft.y());
    LLL->setPos(sceneTopLeft.x() + 650, sceneTopLeft.y());


}
void Game::quitGame() {
    // Display a confirmation dialog
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
