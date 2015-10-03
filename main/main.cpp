#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <thread>

//include C code
extern "C" {
  #include "game.h"
}

constexpr size_t rows = 10;
constexpr size_t collums = 20;

using sixtieths_of_a_sec = std::ratio<1,60>;
constexpr auto frameDur = std::chrono::duration<long,sixtieths_of_a_sec>{1};

void cursesSetup(void) {
  initscr();			// Start curses mode
  raw();				// Line buffering disabled
  keypad(stdscr, TRUE);		// We get F1, F2 etc..
  noecho();			// Don't echo() while we do getch
  nodelay(stdscr, TRUE); //non blocking input mode.
  curs_set(0); //make the cursor invisible.
}

int main(int argc, char** argv) {
  cursesSetup();
  board_t board = read_board("main/res/board.txt");
  snake_t snake = make_snake(rows * collums);
  snake_part start = {3,4};
  game_t game = make_game(board, snake, start);

  draw_snake(snake,board);
  add_apple(board);
  
  int frameCounter = 0;

  for(;;) {
    auto start = std::chrono::high_resolution_clock::now();
    game_error error = game_loop(&game,&frameCounter);

    if (error != GAME_OK){
      break;
    }

    printboard(board);

    move(0,0);
  	refresh();			// Print it on to the real screen
    auto frametime = std::chrono::high_resolution_clock::now() - start;
    std::this_thread::sleep_for(frameDur - frametime);
    frameCounter++;
  }

  delete_board(board);
  delete_snake(snake);

  endwin();			// End curses mode
  return 0;
}
