#include <CUnit/CUnit.h>
#include <ncurses.h>
#include "driver.h"
#include "tests.h"


int driver_setup(void) {
  return 0;
}

int driver_after(void) {
  return 0;
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

void create_cf_test(void) {
  driver_config* cf = create_config(UP);
  CU_ASSERT_TRUE(cf->direction == UP );
  destroy_config(cf);
}

void get_and_set_test(void) {
  driver_config* cf = create_config(UP);

  set_direction(cf, DOWN);
  direction dir = get_direction(cf);

  CU_ASSERT_TRUE(dir == DOWN);
}


CU_pSuite get_driver_suite(void) {

  CU_pSuite suite = CU_add_suite("driver-suite", driver_setup, driver_after);

  CU_add_test(suite,"char_literal_test",range_test);
  CU_add_test(suite,"is_valid_key_test",is_valid_key_test);
  CU_add_test(suite,"create_config_test",create_cf_test);
  CU_add_test(suite,"get_and_set_test",get_and_set_test);
  CU_add_test(suite,"direction",direction_test);


  return suite;
}
