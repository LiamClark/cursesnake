#include "driver.h"
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>

//if the driver exits the os will clean it up for us since the game is then over.
pthread_t* start_driver(driver_config* config) {
  pthread_t* driver_thread =  malloc( sizeof( pthread_t ));
  pthread_create(driver_thread,NULL,driver_func,config);

  return driver_thread;
}

driver_config* create_config(direction dir) {
  driver_config* cf = malloc( sizeof(driver_config));

  cf->direction = dir;
  pthread_mutex_init(&cf->mutex,NULL);

  return cf;
}

void destroy_config(driver_config* config) {
  pthread_mutex_destroy(&config->mutex);
  free(config);
}

void* driver_func(void* config) {
  driver_config* d_config = (driver_config*) config;
  bool running = true;

  while (running) {
    int usr_input = getch();
    input_error err = is_valid_key(usr_input);

    if(err != INPUT_OK) {
      if (usr_input == 'q') {
        running = false;
      }
      direction direction = find_direction(usr_input);
      d_config->direction = direction;
    }

  }

  return NULL;
}

void set_direction(driver_config* config, direction dir) {
  pthread_mutex_lock(&config->mutex);
  config->direction = dir;
  pthread_mutex_unlock(&config->mutex);
}

direction get_direction(driver_config* config) {
  pthread_mutex_lock(&config->mutex);
  direction dir = config->direction;
  pthread_mutex_unlock(&config->mutex);

  return dir;
}

input_error is_valid_key(int key) {
  input_error error = INPUT_INVALID_KEY;
  if ( (KEY_DOWN <= key && key <= KEY_RIGHT) || key == 'q' ) {
    error = INPUT_OK;
  }
  return error;
}
