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
const int key_right = KEY_RIGHT;

void range_test(void) {
  CU_ASSERT_TRUE( key_down < key_right );
  CU_ASSERT_TRUE( KEY_LEFT < key_right );
  CU_ASSERT_TRUE( key_down < KEY_LEFT );
}

void is_valid_key_test(void) {
  CU_ASSERT_TRUE  ( is_valid_key('q') == INPUT_OK );
  CU_ASSERT_TRUE  ( is_valid_key(key_down) == INPUT_OK );
  CU_ASSERT_TRUE ( is_valid_key('X') == INPUT_INVALID_KEY);
}


CU_pSuite get_driver_suite(void) {

  CU_pSuite suite = CU_add_suite("driver-suite", driver_setup, driver_after);

  CU_add_test(suite,"char_literal_test",range_test);
  CU_add_test(suite,"is_valid_key_test",is_valid_key_test);

  return suite;
}
