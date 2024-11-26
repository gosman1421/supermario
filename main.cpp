#include <QApplication>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "game.h"
#include "Score.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Game game;
    game.startGame();

    return app.exec();
}
