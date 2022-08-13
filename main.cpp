#include <iostream>
#include <curses.h>
#include <vector>
#include "ui.h"
#include "game.h"
#include <chrono>
#include "constants.h"

using namespace std;
//Single responsibility principle
// Readability, maintainability perspective
//FPS -> Frames per second

void event_loop(){
  auto last_time = chrono::system_clock::now(); //Gives the current time
  auto current_time = last_time;
  int dt;
  while(true){
    do{
      current_time = chrono::system_clock::now();
      //dt = delta time; casting the time difference in microsec
      dt = chrono::duration_cast<std::chrono::microseconds>(current_time - last_time).count();
    }while(dt < TIME_DELAY_BETWEEN_FRAMES );

    last_time = current_time;
    erase();
    bool continue_playing = execute_frame();
    if(!continue_playing){
      break;
    }
    refresh();
  }
}

int main() {


  init_ui();
  event_loop();
  tear_down_ui();
  
  cout<< endl <<"Thanks for playing slither!"<< endl; //normal terminal 
  return 0; 
} 