#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "GameObject.h"
#include "Constants.h"

class Enemy:public GameObject
{
public:
    Enemy(std::string filePath, int xpos, int ypos);
    void move();
    void update();
    bool isDead();
    bool isOutOfBound();
    void setHealth(int health);
    int getHealth();

private:
    int health = ENEMY_HEALTH;
    int speed = ENEMY_SPEED;
    int bounty = ENEMY_BOUNTY;
    int xSpeed;
    int ySpeed;

};

#endif // ENEMY_H_INCLUDED
