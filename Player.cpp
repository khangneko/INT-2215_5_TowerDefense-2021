#include "Player.h"

int Player::getGold()
{
    return this->gold;
}

int Player::getHP()
{
    return this->HP;
}

void Player::setGold(int gold)
{
    this->gold = gold;
}

void Player::setHP(int HP)
{
    this->HP = HP;
}
