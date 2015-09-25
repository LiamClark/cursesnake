#include "tests.h"
#include "game.h"
#include <ncurses.h>

static char* const test_board[] =
{
  "#####",
  "#   #",
  "#   #",
  "#   #",
  "#####"
};

static const int width = 5;
static const int height = 5;

board_t board;
snake_t snake;
game_t holder;
game_t* game;

int setup_game(void) {
  board = make_board(test_board, width, height);
  snake = make_snake(width * height);
  snake_part start = {1,1};
  holder = make_game(board, snake, start);
  game = &holder;
  return 0;
}

int teardown_game(void) {
  delete_board(board);
  delete_snake(snake);
  return 0;
}

void redo(void){
  teardown_game();
  setup_game();
}

void game_loop_test(void) {
  game_error err = game_drive_snake(game,DOWN);
  CU_ASSERT_EQUAL(err,GAME_OK);
}

void game_wall_collision_test(void) {
  redo();
  game_error err = game_drive_snake(game,UP);
  CU_ASSERT_EQUAL(err,GAME_COLLISION);
}

void game_snake_collision_test(void) {
  redo();
  game_error error = game_drive_snake(game,DOWN);
  CU_ASSERT_EQUAL(error, GAME_OK);
  error = game_drive_snake(game, UP);
  CU_ASSERT_EQUAL(error, GAME_COLLISION);
}

CU_pSuite get_game_suite(void) {
  CU_pSuite suite = CU_add_suite("game-suite",setup_game, teardown_game);

  CU_add_test(suite,"game_loop_test",game_loop_test);
  CU_add_test(suite,"game_wall_test",game_wall_collision_test);
  CU_add_test(suite,"game_snake_test",game_snake_collision_test);

  return suite;
}
