#include "game.h"

game_t make_game(board_t board, snake_t snake, snake_part start) {
  game_t ga = {board,snake,RIGHT};
  add_part(get_body(snake),start);
  return ga;
}

//return of 1 means an error occured.
game_error game_move(game_t* game, int keypress) {
  snake_part next_pos = snake_get_next_move(game->snake, keypress);
  game_error error = check_move(game, next_pos);

  if (error == GAME_OK) {
      snake_part remove = apply_move(game->snake, next_pos);
      set_tile(game->board,remove.y,remove.x,' ');
  }


  return error;
}

game_error check_tile(char tile) {
  game_error error = GAME_OK;
  if (tile == 'X' || tile == '#'){
    error = GAME_COLLISION;
  }
  return error;
}

game_error check_move(game_t* game, snake_part next_pos){
  if ( is_in_range(game->board,next_pos)){
    char tile = get_tile(game->board,next_pos.y,next_pos.x);
    return check_tile(tile);
  }
  return OUT_OF_BOUNDS;
}

game_error game_drive_snake(game_t* game, direction dir) {
  game_error err = game_move(game,dir);

  if (err == GAME_OK ) {
    draw_snake(game->snake, game->board);
  }
  return err;
}

game_error game_loop(game_t* game, int* frame_counter) {
  int ch = getch();
  game_error error = GAME_OK;
  if (ch != ERR) {
    if( ch == 'q') {
      return GAME_OVER;
    } else {
      game->dir = find_direction(ch);
    }
  }
  if (*frame_counter > 5) {
    error = game_drive_snake(game,game->dir);
    *frame_counter = 0;
  }

  return error;
}
