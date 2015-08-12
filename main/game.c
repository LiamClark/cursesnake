#include "game.h"

game_t make_game(board_t board, snake_t snake, snake_part start) {
  game_t ga = {board,snake};
  add_part(get_body(snake),start);
  return ga;
}

//return of 1 means an error occured.
game_error game_move(game_t game, int keypress) {
  snake_part next_pos = snake_get_next_move(game.snake, keypress);
  if ( is_in_range(game.board, next_pos) ) {
      apply_move(game.snake, next_pos);
      return GAME_OK;
  }
  return INVALID_MOVE;
}

game_error game_loop(game_t game, int keypress) {
  int err = game_move(game, keypress);
  if (err == GAME_OK ) {
    draw_snake(game.snake,game.board);
  }
  return GAME_OK;
}
