#include "snake.h"
#include "ui.h"
using namespace std;

vector<pair<int,int>> body;
pair<int, int> last_tail_location;

void init_snake(){
    // When the game starts we want the snake to be of 3 blocks
    body.clear();
    body.push_back({10, 10});
    body.push_back({10, 11});
    body.push_back({10, 12});
}

void paint_snake(){
    attron(COLOR_PAIR(1));
    for(int i = 0; i < body.size(); i++){
        auto location = body[i];
        move(location.first, location.second);
        addstr("\u2591");
    }
    attroff(COLOR_PAIR(1));
}

void reset_snake(){
    init_snake();
}

bool has_collision(){
    //collision of head with the border
    //collision with the snake itself
    pair<int, int> head = body[0];
    int x = head.first;
    int y = head.second;
    
    //coliding with the border 
    if(x == 0 || x == LINES-1 || y == 0 || y == COLS-1)
        return true;

    //Coliding with itself
    //starting with 1 because body[0] is same as head and it will always be true;
    //head can't collide with itself    
    for(int i = 1; i < body.size(); i++){
        if(head == body[i])
            return true;
    }     
    
    //snake is safe
    return false;
}

pair<int,int> move_snake(int direction){
    //with every move we remove the last elemnt and add head according to direction
    last_tail_location = body.back();
    body.pop_back();
    pair<int, int> head = body[0];
    pair<int, int> new_head = {head.first, head.second}; 

    if(direction == LEFT){
        new_head.second -= 1;
    }
    else if(direction == RIGHT){
        new_head.second += 1;
    }
    else if(direction == UP){
        new_head.first -= 1;
    }
    else if(direction == DOWN){
        new_head.first += 1;
    }

    body.insert(body.begin(), new_head);
    return new_head;
}

void grow_snake(){
    body.push_back(last_tail_location);
}

