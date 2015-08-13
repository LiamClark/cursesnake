#ifndef DRIVER_H
#define DRIVER_H

#include <pthread.h>

typedef enum direction {UP,DOWN,LEFT,RIGHT} direction;

typedef enum input_error {INPUT_OK, INPUT_INVALID_KEY} input_error;

typedef struct driver_config {
  direction direction;
  pthread_mutex_t mutex;
}driver_config;

pthread_t* start_driver(driver_config* config);

//function to drive the pthread expects a pointer to a driver_config
void* driver_func(void*);

input_error is_valid_key(int key);

#endif
