#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
private:
    int gold;
    int HP;

public:
    int getGold();
    int getHP();
    void setGold(int gold);
    void setHP(int HP);


};

#endif // PLAYER_H_INCLUDED
