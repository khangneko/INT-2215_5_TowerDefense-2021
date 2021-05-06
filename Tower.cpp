#include "Tower.h"

Tower::Tower(std::string filePath, int xpos, int ypos):GameObject(filePath, xpos, ypos)
{
    angle = 0;
}


bool Tower::isEnemyInRange(Enemy* enemy)
{
    double distance = sqrt(pow(enemy->getXPos() - this->xpos, 2) + pow(enemy->getYPos() - this->ypos, 2));
    return (distance < this->range);
}

void Tower::setTartget(Enemy* enemy)
{
    this->target = enemy;
}

bool Tower::hasTarget()
{
    return (this->target != NULL);
}

void Tower::attack()
{
    int enemyHealth = this->target->getHealth() - this->damage;
    this->target->setHealth(enemyHealth);
}

void Tower::update()
{
    if(this->target!=NULL)
    {
        attack();
        if (this->target->isDead()) this->target = NULL;
    }

}
