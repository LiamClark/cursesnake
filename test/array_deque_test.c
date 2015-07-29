#include "array_deque_test.h"
#include "snake.h"

const int cap = 5;

snake_part_queue queue;
snake_part_queue* q =  &queue;

int setup_queue(void){
  queue = make_queue(cap);
  return 0;
}

int tear_down_queue(void){
  return 0;
}

void make_deque_test(void){
  snake_part p = {3,4};
  add_part(q,p);
  snake_part res = front(q);
  CU_ASSERT_EQUAL(p.x,res.x);
  CU_ASSERT_EQUAL(p.y,res.y);
}

CU_pSuite get_array_deque_suite(void){
  CU_pSuite suite = CU_add_suite("deque-suite",setup_queue,tear_down_queue);

  CU_add_test(suite,"make_deque_test",make_deque_test);
  return suite;
}
