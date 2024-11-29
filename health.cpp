// #include "Health.h"

// Health::Health(int maxHealth, int maxLives)
//     : maxHealth(maxHealth), currentHealth(maxHealth), maxLives(maxLives), currentLives(maxLives) {}

// void Health::takeDamage(int damage) {
//     currentHealth-=damage;
//     if (currentHealth<=0) {
//         loseLife();
//         if (hasLivesLeft()) {
//             resetHealth();
//         }
//     }
// }
// void Health::heal(int amount){
//     currentHealth +=amount;
//     if (currentHealth>maxHealth){
//         currentHealth=maxHealth;
//     }
// }
// bool Health::isAlive() const{
//     return currentHealth >0;
// }
// void Health::resetHealth(){
//     currentHealth = maxHealth ;
// }



// // Life Management
// void Health::loseLife(){
//     if (currentLives > 0){
//         currentLives--;
//     }
// }
// void Health::gainLife() {
//     if (currentLives < maxLives) {
//         currentLives++ ;
//     }
// }
// bool Health::hasLivesLeft() const {
//     return currentLives > 0;
// }
// void Health::resetLives() {
//     currentLives = maxLives;
// }





// QString Health::getHealthBar()const {
//     QString bar;
//     for (int i = 0; i < maxHealth; i++) {
//         bar += (i < currentHealth) ? "|" : "-" ;
//     }
//     return bar;
// }
// QString Health::getLivesDisplay()const{
//     return QString("Lives: %1").arg(currentLives);
// }




// int Health::getCurrentHealth()const{
//     return currentHealth ;
// }
// int Health::getCurrentLives()const{
//     return currentLives;
// }

#include "Health.h"

Health::Health(int maxHealth, int maxLives, QGraphicsItem* parent)
    : QGraphicsTextItem(parent), maxHealth(maxHealth), currentHealth(maxHealth), maxLives(maxLives), currentLives(maxLives) {
    // Set initial display
    setDefaultTextColor(Qt::yellow);
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
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
    updateDisplay();
}

bool Health::isAlive() const {
    return currentLives > 0;
}

void Health::resetHealth() {
    currentHealth = maxHealth;
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
    currentLives = maxLives;
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
    setPlainText(QString("Health: %1/%2\nLives: %3/%4")
                     .arg(currentHealth)
                     .arg(maxHealth)
                     .arg(currentLives)
                     .arg(maxLives));
}
