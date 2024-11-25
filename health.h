#ifndef HEALTH_H
#define HEALTH_H

#include <QString>

class Health {
private:
    int maxHealth;
    int currentHealth;
    int maxLives;
    int currentLives;

public:
    // Constructor
    Health(int maxHealth, int maxLives);

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

    // UI Helpers
    QString getHealthBar() const;
    QString getLivesDisplay() const;

    // Getters for testing/debugging
    int getCurrentHealth() const;
    int getCurrentLives() const;
};

#endif // HEALTH_H
