#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "snake.h"

typedef enum game_error {GAME_OK,INVALID_MOVE,GAME_OVER} game_error;

typedef struct game{
  board_t board;
  snake_t snake;
}game_t;

game_t make_game(board_t board, snake_t snake, snake_part start);

game_error game_move(game_t game, char keypress);

game_error game_loop(game_t game, char keypress);

#endif