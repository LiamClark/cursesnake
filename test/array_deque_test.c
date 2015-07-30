#include "array_deque_test.h"
#include "snake.h"

const int cap = 5;

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
  queue = make_queue(cap);
  q = &queue;
  return 0;
}

int tear_down_queue(void){
  delete_queue(q);
  return 0;
}

void make_deque_test(void){
  snake_part p = {3,4};
  add_part(q,p);
  snake_part res = front(q);
  CU_ASSERT_EQUAL(p.x,res.x);
  CU_ASSERT_EQUAL(p.y,res.y);
  CU_ASSERT_EQUAL(q->head, 1);
}

void good_weather_test(void){
  for( int i = 0; i < cap; i++) {
    add_part(q, parts[i]);
    CU_ASSERT_EQUAL(parts[i].x, front(q).x);
    CU_ASSERT_EQUAL(parts[i].y, front(q).y);
  }
}

CU_pSuite get_array_deque_suite(void){
  CU_pSuite suite = CU_add_suite("deque-suite",setup_queue,tear_down_queue);

  CU_add_test(suite,"make_deque_test",make_deque_test);
  CU_add_test(suite,"good_weather_test",good_weather_test);
  return suite;
}
