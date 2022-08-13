#ifndef DEF_FOOD
#define DEF_FOOD

#include <vector>
#include "curses.h"
#include "constants.h"
#include <experimental/random>
using namespace std;


void init_food();
void paint_food();
pair<int, int> make_food();
bool try_consume_food(pair<int, int> head);

#endif