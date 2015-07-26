#include "array_deque_test.h"
#include "snake.h"

const int cap = 5;

snake_part_queue queue;
snake_part_queue* q =  &snake_part_queue;

int setup(void){
  queue = make_queue(cap);
  return 0;
}

int after(void){
  return 0;
}

void make_deque_test(void){
  snake_part p = {3,4};
  add_part(q,p);
  front(15)
  CU_ASSERT_EQUALS(p.x,res.x);
  CU_ASSERT_EQUALS(p.y,res.y);
}

CU_pSuite get_array_deque_suite(void){
  CU_pSuite suite = CU_add_suite("deque-suite",setup,after);

  CU_add_test(suite,"make_deque_test",make_deque_test);
  return suite;
}
