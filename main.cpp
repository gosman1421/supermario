#include <QApplication>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsview>
#include "coin.h"
#include "enemy.h"
#include "game.h"
#include "GameLevel.h"
#include "Health.h"
#include "player.h"
#include "Score.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsView * view = new QGraphicsView(scene);
    view->setFixedSize(800, 600);
    player* player1 = new player();
    player1->setFlag(QGraphicsItem::ItemIsFocusable);

    player1->setPos(view->width()/2,view->height()-player1->rect().height());

    scene->addItem(player1);



    view->setScene(scene);
    view->show();
    return app.exec();
}
