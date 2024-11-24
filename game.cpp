#include "Game.h"
#include <QKeyEvent>
#include <QDebug>




Game::Game()
    : score(0),currentLevel(1){
    scene=new QGraphicsScene();
    view=new QGraphicsView(scene);
    gameTimer=new QTimer(this);
    health=new Health(100, 3);

    connect(gameTimer, &QTimer::timeout,this,&Game::updateGame);

    initGame();
}



Game::~Game(){
    delete scene ;
    delete view;
    delete gameTimer ;
    delete health;
}
void Game::initGame(){
    loadLevel (currentLevel);
    updateHUD ();
}
void Game::loadLevel(int level) {
    scene-> clear();

    QGraphicsTextItem* levelText =new QGraphicsTextItem(QString("level 1").arg(level));
    levelText->setPos(10, 10);
    scene->addItem(levelText);
}
void Game::startGame() {
    gameTimer->start(16) ;
    qDebug()<< "game started!";
}

void Game::pauseGame() {
    gameTimer->stop();
    qDebug()<< "game paused.";
}
void Game::restartLevel() {
    health->resetHealth();
    loadLevel(currentLevel);
    qDebug() <<"level restarted." ;
}
void Game::gameOver(){
    qDebug() << "game Over!";
    gameTimer->stop();
}
void Game::nextLevel(){
    currentLevel++;
    loadLevel(currentLevel);
}
void Game::checkCollisions(){
    qDebug() << "checking collisions...";
}
void Game::updateHUD(){
    qDebug()<< "s core:" <<score<< "health:" <<health->getCurrentHealth() ;
}
void Game::updateGame(){
    checkCollisions();
    updateHUD() ;
}
