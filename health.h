// #ifndef HEALTH_H
// #define HEALTH_H

// #include <QString>

// class Health {
// private:
//     int maxHealth;
//     int currentHealth;
//     int maxLives;
//     int currentLives;

// public:
//     // Constructor
//     Health(int maxHealth, int maxLives);

//     // Health Management
//     void takeDamage(int damage);
//     void heal(int amount);
//     bool isAlive() const;
//     void resetHealth();

//     // Life Management
//     void loseLife();
//     void gainLife();
//     bool hasLivesLeft() const;
//     void resetLives();

//     // UI Helpers
//     QString getHealthBar() const;
//     QString getLivesDisplay() const;

//     // Getters for testing/debugging
//     int getCurrentHealth() const;
//     int getCurrentLives() const;
// };

// #endif // HEALTH_H

#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QString>
#include <QFont>

class Health : public QGraphicsTextItem {
private:
    int maxHealth;
    int currentHealth;
    int maxLives;
    int currentLives;

    void updateDisplay(); // Helper to refresh the text display

public:
    // Constructor
    Health(int maxHealth, int maxLives, QGraphicsItem* parent = nullptr);

    // Health Management
    void takeDamage(int damage);
    void heal(int amount);
    bool isAlive() const;
    void resetHealth();

    // Life Management
    void loseLife();
    void gainLife();
    bool hasLivesLeft() const;
    void resetLives();

    // Getters for testing/debugging
    int getCurrentHealth() const;
    int getCurrentLives() const;
};

#endif // HEALTH_H
