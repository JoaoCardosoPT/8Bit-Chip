#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdint.h>

// The sturcture for the instructions
// Prevents else if in assembler.c
typedef struct
{
    const char *name;
    uint8_t opcode;
    int size;
} Instructions;

static const Instructions instructions[] =
    {
        {"HALT", 0x00, 1},
        {"LOAD_R0", 0x01, 2},
        {"LOAD_R1", 0x02, 2},
        {"ADD", 0x10, 1},
        {"MULTIPLY", 0x11, 1},
        {"SUBTRACT", 0x12, 1},
};

#endif