#include "game.h"
using namespace std;

int direction;
int game_state = BEFORE_START;
int score;
int lives;
int ticks_in_snake_reset;

void start_game(){
    init_snake();
    init_food();
    direction = UP;
    game_state = STARTED; 
    score = 0;
    lives = INTIAL_LIVES;
}

void end_game(){
    game_state = ENDED;
}

void paint_status(){
    //paints the score
    attron(COLOR_PAIR(2));
    move(0, 5);
    printw(" Score: %d ", score);

    move(0, COLS-15);
    for(int i = 0; i < lives; i++){
        addstr(" *");
        if(i == lives - 1)
            addstr(" ");
    }

    if(game_state == BEFORE_START){
        move(LINES-1, 10);
        addstr(" Press space to start! ");
    }
    else if(game_state == ENDED){
        move(LINES-1,10);
        //add score
        addstr(" Press space to Restart!:D Press Q to Quit :( ");
    }
    else if(game_state == RESET_SNAKE){
        move(LINES-1,10);
        //add score
        addstr(" You just lost a life! :( ");
        //addstr(" You just lost a life! :( Press space key to continue");

    }
    attroff(COLOR_PAIR(2));
}

bool execute_frame(){
    paint_border();
    paint_status();

    char key = getch();
    if(game_state == BEFORE_START){
        move(10, 10);
        addstr("Press space to start!");
        if(key == 32){
            start_game();
        }
    }
    else if(game_state == STARTED){
        //If a key is pressed, need some reaction.
        //Regardless the snake has to move continuously
        if(key == UP and direction != DOWN){
            direction = UP;
        }    
        else if(key == DOWN and direction != UP){
            direction = DOWN;
        }    
        else if(key == RIGHT and direction != LEFT){
            direction = RIGHT;
        }    
        else if(key == LEFT and direction != RIGHT)
            direction = LEFT; 

        pair<int, int> head = move_snake(direction);
        if(try_consume_food(head)){
            grow_snake();
            //erase food, generate new food
            score++;
        }

        paint_snake();    
        paint_food();
        if(has_collision()){
            lives -= 1;
            reset_snake();
            game_state = RESET_SNAKE;
            ticks_in_snake_reset = 30;
            if(lives == -1){
                end_game();
            }
            
        }
        
    }
    else if(game_state == RESET_SNAKE){
        // if(key == 32){
        //     game_state = STARTED;
        // }

        ticks_in_snake_reset--;
        if(key == 32 || ticks_in_snake_reset == 0){
            game_state = STARTED;
        }
        if(ticks_in_snake_reset % 2 == 0){
            paint_snake();

        }
        paint_food();
    }
    else{
        paint_snake();
        paint_food();
        move(10,10);
        //add score
        addstr("Press space to Restart! :D");
        move(11,10);
        addstr("Press Q to Quit :(");

        if(key == 32){
            start_game();
        }else if(key == QUIT){
            return false; //don't want to execute_frame()
        }
    }
    return true; //continue executing the frame
}