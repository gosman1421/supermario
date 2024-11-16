#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <Qpen>
#include "score.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0, 0, 800, 600);
    QPen RedPen(Qt::red);
    rect->setPen(RedPen);
    scene->addItem(rect);
    QGraphicsView * view = new QGraphicsView(scene);
    view->setFixedSize(800, 600);
    Score *score = new Score();
    scene->addItem(score);
    score->setPos(20, 20);
    view->show();
    return a.exec();
}
