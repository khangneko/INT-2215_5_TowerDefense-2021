#ifndef CONSTANTS_H_
#define CONSTANTS_H_

// Wave point 1: (100, 420)
// Wave point 2: (355, 420)
// Wave point 3: (355, 100)
// Wave point 4: (610, 100)
// Wave point 5: (610, 666)

const int TILE_SIZE = 64;
const int TILE_HORIZONTAL = 18;
const int TILE_VERTICAL = 12;

const int UI_HORIZONTAL = 200;
const int GAME_WIDTH = TILE_SIZE*TILE_HORIZONTAL;
const int GAME_HEIGHT = TILE_SIZE*TILE_VERTICAL;
const int SCREEN_WIDTH = GAME_WIDTH + UI_HORIZONTAL;
const int SCREEN_HEIGHT = GAME_HEIGHT;

const int SPAWN_X = 100;
const int SPAWN_Y = 672;
const int SPAWN_RATE = 20;

const std::string TOWER_FILE_PATH = "Assets/Tower/normal.png";
const int TOWER_COST = 10;
const int TOWER_DAMAGE = 10;
const double TOWER_RANGE = 100;

const std::string ENEMY_FILE_PATH = "Assets/Enemy/Normal.png";
const int ENEMY_HEALTH = 10;
const int ENEMY_SPEED = 30;
const int ENEMY_BOUNTY = 20;
const int ENEMY_NUMBER = 5;

const int BUTTON_WIDTH = 128;
const int BUTTON_HEIGHT = 128;


#endif // CONSTANTS_H_
