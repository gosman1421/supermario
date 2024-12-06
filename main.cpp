#include <QApplication>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "game.h"
#include "Score.h"
#include "welcomewindow.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    welcomewindow welcome;
    welcome.show();

    return app.exec();
}
