#ifndef GAMELEVEL_H
#define GAMELEVEL_H \
    // Just a placeholder/temporary .h file made by gpt
#include <QObject>
#include <QString>

class GameLevel {
private:
    int levelNumber; // The current level number
    QString levelName; // Optional: Name of the level

public:
    // Constructor
    GameLevel(int number, QString name = "Level")
        : levelNumber(number), levelName(name) {}
    // Getters
    int getLevelNumber() const { return levelNumber; }
    QString getLevelName() const { return levelName; }

    // Setters
    void setLevelNumber(int number) { levelNumber = number; }
    void setLevelName(QString name) { levelName = name; }

    // Optional: Placeholder for loading level assets
    void loadLevel() {
        // Add logic to load assets specific to this level
    }
};

#endif // GAMELEVEL_H
