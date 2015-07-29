#include <CUnit/CUnit.h>
#include "snake_test.h"
#include "snake.h"

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

CU_pSuite get_snake_suite(void){
  CU_pSuite suite = CU_add_suite("snake-suite",setup_snake,tear_down_snake);

  CU_add_test(suite,"make_board_test",make_snake_test);


  return suite;
}
