#include <iostream>
#include <curses.h>
using namespace std; 
//Definition of all functions declared in ui.h
#include "ui.h"

void init_ui(){
  setlocale(LC_ALL, ""); //overrides the default locale of ISO-8859
  initscr();  //initializes the ncurses mode
  nodelay(stdscr, TRUE); //make getch nonblocking call
  noecho();//turns off echo behavious in terminal(w,a,s,d gets printed every time we press it)
  curs_set(0);//no cursor on screen

  start_color();
  init_pair(1, COLOR_WHITE, COLOR_MAGENTA);//snake
  init_pair(2, COLOR_MAGENTA, COLOR_BLACK);//status, food, lives
  init_pair(4, COLOR_WHITE, COLOR_BLACK);//border

  keypad(stdscr, TRUE); //enables reading of backspace, function, arrow, del and other keys
  
}

void tear_down_ui(){
  endwin(); //exits the ncurses mode

}

void paint_border(){
  
  //cout<<"#"; //normal terminal
  //addstr("Hello!"); adds string to the ncurses window
  //the constant "COLS" is a part of ncurses which tells the width of the terminal
  //LINES gives the number of lines in the screen(ncurses)
  attron(COLOR_PAIR(4));
  for(int i = 0; i < COLS; i++){
    move(0, i);
    addstr("\u2588");
    move(LINES-1, i);
    addstr("\u2588");
  }
  for(int i = 0; i < LINES; i++){
    move(i, 0);
    addstr("\u2588");
    move(i, COLS-1);
    addstr("\u2588");
  }
  attroff(COLOR_PAIR(4));
}

