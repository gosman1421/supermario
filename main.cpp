#include <QApplication>
#include <QWidget> //replace this with your main window class header if

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create the main window or widget
    QWidget window; // Replace QWidget with your custom main window class, e.g., MainWindow
    window.show();

    return app.exec();
}

