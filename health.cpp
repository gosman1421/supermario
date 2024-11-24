#include "Health.h"

Health::Health(int maxHealth, int maxLives)
    : maxHealth(maxHealth), currentHealth(maxHealth), maxLives(maxLives), currentLives(maxLives) {}

void Health::takeDamage(int damage) {
    currentHealth-=damage;
    if (currentHealth<=0) {
        loseLife();
        if (hasLivesLeft()) {
            resetHealth();
        }
    }
}
void Health::heal(int amount){
    currentHealth +=amount;
    if (currentHealth>maxHealth){
        currentHealth=maxHealth;
    }
}
bool Health::isAlive() const{
    return currentHealth >0;
}
void Health::resetHealth(){
    currentHealth = maxHealth ;
}



// Life Management
void Health::loseLife(){
    if (currentLives > 0){
        currentLives--;
    }
}
void Health::gainLife() {
    if (currentLives < maxLives) {
        currentLives++ ;
    }
}
bool Health::hasLivesLeft() const {
    return currentLives > 0;
}
void Health::resetLives() {
    currentLives = maxLives;
}





QString Health::getHealthBar()const {
    QString bar;
    for (int i = 0; i < maxHealth; i++) {
        bar += (i < currentHealth) ? "|" : "-" ;
    }
    return bar;
}
QString Health::getLivesDisplay()const{
    return QString("Lives: %1").arg(currentLives);
}




int Health::getCurrentHealth()const{
    return currentHealth ;
}
int Health::getCurrentLives()const{
    return currentLives;
}
