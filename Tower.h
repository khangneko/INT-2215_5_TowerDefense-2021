#ifndef TOWER_H_INCLUDED
#define TOWER_H_INCLUDED

#include "GameObject.h"
#include "Constants.h"
#include "Enemy.h"
#include <cmath>

class Tower:public GameObject
{
public:
    Tower(std::string filePath, int xpos, int ypos);
    void attack();
    void setTartget(Enemy* enemy);
    void update();
    bool isEnemyInRange(Enemy* enemy);
    bool hasTarget();


private:
    int damage = TOWER_DAMAGE;
    int cost = TOWER_COST;
    double range = TOWER_RANGE;
    Enemy* target = NULL;
};

#endif // TOWER_H_INCLUDED
