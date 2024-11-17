#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Create a scene
    QGraphicsScene *scene = new QGraphicsScene();
    player *player1 = new player();
    player1->setPos(10, 10); // Set initial position of the player in the scene
    scene->addItem(player1);  //

    // Create a view to visualize the scene
    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(800, 600);        // Set fixed size for the view
    scene->setSceneRect(0, 0, 800, 600); // Set the scene boundaries
    // Enable keyboard focus on the player
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
   //player1->setFocus();
    // Show the view
            view->show();
//    player w;
//    w.show();
    return a.exec();
}






