#include "Enemy.h"

Enemy::Enemy(std::string filePath, int xpos, int ypos):GameObject(filePath, xpos , ypos)
{

}

bool Enemy::isDead()
{
    return (this->health <= 0);
}

bool Enemy::isOutOfBound()
{
    return (this->xpos > GAME_WIDTH);
}
void Enemy::move()
{
    if (this->xpos <= 100 && this->ypos > 420)
    {
        this->xSpeed = 0;
        this->ySpeed = -this->speed;
    }
    // Wave point 1
    if (this->xpos <= 355 && this->ypos <= 420)
    {
        this->angle = 0;
        this->xSpeed = this->speed;
        this->ySpeed = 0;
    }
    //Wave point 2
    if (this->xpos >= 355 && this->ypos >= 100)
    {
        this->angle = -90;
        this->xSpeed = 0;
        this->ySpeed = -this->speed;

    }
    //Wave point 3
    if (this->xpos <= 610 && this->ypos <= 100)
    {
        this->angle = 0;
        this->xSpeed = this->speed;
        this->ySpeed = 0;
    }
    //Wave point 4
    if (this->xpos >= 610 && this->ypos <= 666)
    {
        this->angle = 90;
        this->xSpeed = 0;
        this->ySpeed = this->speed;
    }
    //Wave point 5;
    if (this->xpos >= 610 && this->ypos >= 666)
    {
        this->angle = 0;
        this->xSpeed = this->speed;
        this->ySpeed = 0;
    }
    this->xpos += this->xSpeed;
    this->ypos += this->ySpeed;
    this->rect.x = this->xpos -32;
    this->rect.y = this->ypos -32;
}

void Enemy::update()
{
    this->move();
    if (this->isOutOfBound())
    {
        SDL_DestroyTexture(objTexture);

    }
}

void Enemy::setHealth(int health)
{
    this->health = health;
}

int Enemy::getHealth()
{
    return this->health;
}
