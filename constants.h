#ifndef DEF_CONSTANTS
#define DEF_CONSTANTS
//global settings for this program

const char snake_color = 'r';
//10 frames per second => 1 frame per 0.1 sec
//How long does a frame last in microsecond?
//0.1 seconds = 100000 microseconds
const int TIME_DELAY_BETWEEN_FRAMES = 100000; //increasing this will decrese the speed of snake

const int UP = 'w';
const int LEFT = 'a';
const int DOWN = 's';
const int RIGHT = 'd';
const int QUIT = 'q';

// const int UP = 259;
// const int LEFT = 258;
// const int DOWN = 260;
// const int RIGHT = 261;

const int BEFORE_START = 0,
          STARTED = 1,
          ENDED = 2,
          RESET_SNAKE = 3;

const int INTIAL_LIVES = 3;

const int FOOD_COUNT = 5;

#endif