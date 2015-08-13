#include "driver.h"
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>

pthread_t* start_driver(driver_config* config) {
  pthread_t* driver_thread =  malloc( sizeof( pthread_t ));
  pthread_create(driver_thread,NULL,driver_func,config);

  return driver_thread;
}

void* driver_func(void* config) {
  driver_config* d_config = (driver_config*) config;
  int usr_input;
  bool running = true;

  while (running) {
    usr_input = getch();
  }

  return NULL;
}

input_error is_valid_key(int key) {
  input_error error = INPUT_INVALID_KEY;
  if ( (KEY_DOWN <= key && key >= KEY_RIGHT) || key == 'q' ) {
    error = INPUT_OK;
  }
  return error;
}
