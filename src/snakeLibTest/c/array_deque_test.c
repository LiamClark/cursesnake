#include "gradle_cunit_register.h"
#include "tests.h"
#include <CUnit/CUnit.h>
#include <stdbool.h>
#include "snake.h"

int capacity = 5;

const int snake_length = 6;

const snake_part parts[] = {
  {1,1},
  {1,2},
  {1,3},
  {2,3},
  {3,3},
  {3,4}
};

snake_part_queue queue;
snake_part_queue* q;

int setup_queue(void){
  queue = make_queue(capacity);
  q = &queue;
  return 0;
}

int tear_down_queue(void){
  delete_queue(q);
  return 0;
}

bool compare_parts(snake_part a , snake_part b){
  return (a.x == b.x) && (a.y == b.y);
}

void redo_array_deque_test(int cap){
  tear_down_queue();
  capacity = cap;
  setup_queue();
}

void make_deque_test(void){
  snake_part p = {3,4};
  add_part(q,p);
  snake_part res = tail(q);
  CU_ASSERT_TRUE(compare_parts(p, res));
  CU_ASSERT_EQUAL(q->tail, 1);
}

void good_weather_test(void){
  redo_array_deque_test(2);
  add_part(q,parts[0]);
  add_part(q,parts[1]);
  snake_part end = take_part(q);
  CU_ASSERT_TRUE(compare_parts(end, parts[0]));
  add_part(q,parts[2]);
  CU_ASSERT_TRUE(compare_parts(tail(q),parts[2]));
  CU_ASSERT_EQUAL(q->head,1);
  CU_ASSERT_EQUAL(q->tail,0);
  CU_ASSERT_EQUAL(part_count(q),2);
}

int counter = 0;

void test_func(board_t t,snake_part* sp){
  CU_ASSERT_TRUE(compare_parts(parts[counter],*sp));
  counter++;
}

void print_func(board_t t,snake_part* sp){
  printf("x = %d y = %d\n",sp->x, sp->y);
}

void iterate_test(void){
  redo_array_deque_test(6);
  for(int i = 0; i < snake_length; i++){
    add_part(q,parts[i]);
  }
  iterate(q,test_func,NULL);
}

void gradle_cunit_register(void) {
  CU_pSuite suite = CU_add_suite("deque-suite",setup_queue,tear_down_queue);

  CU_add_test(suite,"make_deque_test",make_deque_test);
  CU_add_test(suite,"good_weather_test",good_weather_test);
  CU_add_test(suite,"iterate_test",iterate_test);

  get_snake_suite();
  get_board_suite();
  get_game_suite();
}
