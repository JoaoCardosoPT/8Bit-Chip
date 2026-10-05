#ifndef LOADER_H
#define LOADER_H 

#include <stdint.h>
#include <stdbool.h>
bool load_program(const char *path, uint16_t start_address);

#endif
