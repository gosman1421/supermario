#include <QApplication>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "game.h"
#include "Score.h"
#include "welcomewindow.h"
#include <QMediaPlayer>
#include <QUrl>
#include <QAudioOutput>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMediaPlayer* songplayer= new QMediaPlayer;
    QAudioOutput* audio= new QAudioOutput;
    songplayer->setAudioOutput(audio);
    songplayer->setSource(QUrl::fromLocalFile("C:/Users/AUC/Documents/GitHub/supermario/01. Ground Theme.mp3"));
    audio->setVolume(100);
    songplayer->play();
    welcomewindow welcome;
    welcome.show();

    return app.exec();
}
