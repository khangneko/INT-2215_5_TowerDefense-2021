#ifndef TOWER_H_INCLUDED
#define TOWER_H_INCLUDED

#include "GameObject.h"
#include "Constants.h"
#include "Enemy.h"

class Tower:public GameObject
{
public:
    Tower(std::string filePath, int xpos, int ypos);
    void attack();


private:
    int damage = TOWER_DAMAGE;
    int cost = TOWER_COST;
    int range = TOWER_RANGE;
    Enemy* target;
};

#endif // TOWER_H_INCLUDED
