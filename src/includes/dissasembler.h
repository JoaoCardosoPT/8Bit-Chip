#ifndef DISSASEMBLER_H
#define DISSASEMBLER_H
#include <stddef.h>
#include <stdint.h>

void dissasemble(const uint8_t *code, size_t size);

#endif
