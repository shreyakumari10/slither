#include "food.h"
#include "ui.h"
using namespace std;

vector<pair<int, int>> nibbles;

pair<int, int> make_food(){
    //generates and returns random food items
    return {experimental::randint(1, LINES-2), experimental::randint(1, COLS-2)};
}

void init_food(){
    nibbles.clear();
    for(int i = 0; i < FOOD_COUNT; i++)
        nibbles.push_back(make_food());
}

void paint_food(){
    attron(COLOR_PAIR(2));
    for(int i = 0; i < nibbles.size(); i++){
        pair<int, int> loc = nibbles[i];
        move(loc.first, loc.second);
        addstr("o");
    }
    attron(COLOR_PAIR(2));
}

bool try_consume_food(pair<int, int> head){
    //if food at head location> consume it, generate new food and return true
    //if no food at head, return false
    for(int i = 0; i < nibbles.size(); i++){
        if(head.first == nibbles[i].first and head.second == nibbles[i].second){
            //food is present at head
            nibbles.erase(nibbles.begin()+i); //removes the food item
            nibbles.push_back(make_food()); //adds a new one
            return true; // food is present & consumed confirmation
        }
    }
    return false;
}