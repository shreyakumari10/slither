#ifndef DEF_GAME

#define DEF_GAME

#include<vector>
#include "curses.h"
#include "ui.h"
#include "constants.h"
#include "snake.h"
#include "food.h"

void start_game();
bool execute_frame();
void end_game();
void paint_status();

#endif