#include "Health.h"

Health::Health(int maxHealth, int maxLives, QGraphicsItem* parent)
    : QGraphicsTextItem(parent), maxHealth(maxHealth), currentHealth(maxHealth), maxLives(maxLives), currentLives(maxLives) {
    // Set initial display
    setDefaultTextColor(Qt::black);
    setFont(QFont("Arial", 14));
    updateDisplay();
}

void Health::takeDamage(int damage) {
    currentHealth -= damage;
    if (currentHealth < 0) {
        currentHealth = 0;
        loseLife();
    }
    updateDisplay();
}

void Health::heal(int amount) {

    currentHealth += amount;
    if (currentHealth
        > maxHealth) {
        currentHealth = maxHealth;

    }
    updateDisplay();
}

bool Health::isAlive() const {
    return currentLives > 0;
}

void Health::resetHealth() {
    currentHealth = maxHealth;
    currentLives = maxLives;
    updateDisplay();
}

void Health::loseLife() {
    if (currentLives > 0) {
        currentLives--;
        currentHealth = maxHealth; // Reset health when losing a life
    }
    updateDisplay();
}

void Health::gainLife() {
    if (currentLives < maxLives) {
        currentLives++;
    }
    updateDisplay();
}

bool Health::hasLivesLeft() const {
    return currentLives > 0;
}

void Health::resetLives() {
    currentLives = currentLives-1;
    updateDisplay();
}

int Health::getCurrentHealth() const {
    return currentHealth;
}

int Health::getCurrentLives() const {
    return currentLives;
}

void Health::updateDisplay() {
    // Update the displayed text for health and lives
    setPlainText(QString("Health: %1/%2\nLives Left: %3")
                     .arg(currentHealth)
                     .arg(maxHealth)
                     .arg(currentLives)
                     .arg(maxLives));
}
