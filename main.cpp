#include <QApplication>
#include <QWidget> //replace this with your main window class header if
#include <QGraphicsRectItem>
#include <QGraphicsview>
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsRectItem* rect = new QGraphicsRectItem();
    rect->setRect(0,0,100,100);
    scene->addItem(rect);
    QGraphicsView * view = new QGraphicsView(scene);
    view->show();
    // Create the main window or widget
    QWidget window; // Replace QWidget with your custom main window class, e.g., MainWindow
    window.show();

    return app.exec();
}

