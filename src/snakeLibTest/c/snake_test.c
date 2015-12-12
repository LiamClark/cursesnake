#include <CUnit/CUnit.h>
#include "snake.h"
#include "tests.h"
#include <ncurses.h>

static const int capacity = 3;

int setup_snake(void){
  return 0;
}

int tear_down_snake(void){
  return 0;
}

void make_snake_test(void){
  snake_t snake = make_snake(capacity);
}

const int key_down = KEY_DOWN;
const int key_up = KEY_UP;
const int key_left = KEY_LEFT;
const int key_right = KEY_RIGHT;

void range_test(void) {
  CU_ASSERT_TRUE( key_down < key_right );
  CU_ASSERT_TRUE( key_left < key_right );
  CU_ASSERT_TRUE( key_down < key_left );
}

void direction_test(void) {
  CU_ASSERT_EQUAL( LEFT, find_direction(key_left));
  CU_ASSERT_EQUAL( RIGHT, find_direction(key_right));
  CU_ASSERT_EQUAL( DOWN, find_direction(key_down));
  CU_ASSERT_EQUAL( UP, find_direction(key_up));
}

void is_valid_key_test(void) {
  CU_ASSERT_TRUE  ( is_valid_key('q') == INPUT_OK );
  CU_ASSERT_TRUE  ( is_valid_key(key_down) == INPUT_OK );
  CU_ASSERT_TRUE ( is_valid_key('X') == INPUT_INVALID_KEY);
}


CU_pSuite get_snake_suite(void){
  CU_pSuite suite = CU_add_suite("snake-suite",setup_snake,tear_down_snake);

  CU_add_test(suite,"char_literal_test",range_test);
  CU_add_test(suite,"is_valid_key_test",is_valid_key_test);
  CU_add_test(suite,"direction",direction_test);


  CU_add_test(suite,"make_board_test",make_snake_test);

  return suite;
}
