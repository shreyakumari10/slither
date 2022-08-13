#ifndef DEF_SNAKE
#define DEF_SNAKE

#include <vector>
#include "ui.h"
#include "ncurses.h"
#include "constants.h"
using namespace std;


void init_snake();
void paint_snake();
bool has_collision();
pair<int,int> move_snake(int direction);
void grow_snake();
void reset_snake();
// int get_size();
// void move_snake(int direction);
// void grow_snake(int direction);
// void set_speed(int speed);
// void init_snake();//restarting the game

#endif