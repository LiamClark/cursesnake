#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <ncurses.h>
#include "snake.h"

typedef enum game_error {GAME_OK, GAME_OVER,OUT_OF_BOUNDS,
   GAME_COLLISION} game_error;

typedef struct game{
  board_t board;
  snake_t snake;
  direction dir;
}game_t;

game_t make_game(board_t board, snake_t snake, snake_part start);

game_error game_drive_snake(game_t* game, direction dir);

game_error game_move(game_t* game, int keypress);

game_error game_loop(game_t* game,int frame_counter);

direction handle_input(direction prev,int ch);

game_error check_move(game_t* game, snake_part next_pos);
game_error check_tile(char tile);

#endif
