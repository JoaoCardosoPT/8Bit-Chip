// Tell our parts of our project which assembler functions they can call and how to call them
#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdint.h>
void assemble_line(const char *line, uint8_t *output_buffer, int *buffer_size);

#endif