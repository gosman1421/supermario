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

Game::Game() : score(0), currentLevel(1) {
    // Create the scene and view


    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    scene->clear();
    //displaymainwindow();

    // Set the view's fixed size
    view->setFixedSize(800, 600);
    view->setSceneRect(0, 0, 2000, 600); // Match scene dimensions to the view


    // Load the background image
    QPixmap backgroundPixmap("C:/Users/AUC/Documents/GitHub/supermario/rb_2150262151.png");

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
    gameTimer = new QTimer(this);
    health = new Health(100, 3);
    scoreManager = new Score();
    mainPlayer = new player();
    mainPlayer->scene = scene;

    // Add game elements to the scene
    scene->addItem(scoreManager);
    scene->addItem(mainPlayer);
    simulateMouseClick();
    scene->addItem(health);
    // Update the scene
    scene->update();
    connect(mainPlayer, &player::gameOver, this, &Game::gameOver);

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

    for (int i = 0; i < 5; i++) {
        coin* newCoin = new coin(scene, scoreManager);
        newCoin->setPos(i * 150 + 100, 550);
        coins.append(newCoin);
    }


    Enemy* newEnemy = new Enemy(scene, Enemy::Moving, scoreManager, 10, 560, 800, 0);
    enemies.append(newEnemy);
    QGraphicsPixmapItem* finishLine = new QGraphicsPixmapItem(QPixmap("/Users/ghadasherif/Downloads/finish-line-flag-vector-38518916.jpg"));
    finishLine->setPos(900, 500);  // Adjust position to fit the scene
    finishLine->setScale(0.1);      // Adjust scale if needed
    scene->addItem(finishLine);

    health->setPos(0, 40);
    scene->update();

    // Store a reference to the finish line (if needed globally)
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
    gameTimer->stop();  // Stop the game timer

    QMessageBox::critical(
        nullptr,
        "Game Over",
        "Game Over! You have no more lives left.",
        QMessageBox::Ok
        );

    welcomewindow* welcome = new welcomewindow();
    welcome->show();

    // Clean up the game elements
    delete scene;
    delete view;
    delete gameTimer;
    delete health;
    delete scoreManager;
    delete mainPlayer;

    // Exit the application or reset the state for replay
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
    if (mainPlayer->collidesWithItem(finishLine)) {  // Check collision
            gameOver();
            return;  // Exit the function to prevent further updates
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
    // Map the view's top-left corner to the scene coordinates
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
