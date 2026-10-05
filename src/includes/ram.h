#ifndef RAM_H
#define RAM_H

#include <stdint.h>
#define RAM_SIZE 65536

#define KERNEL_SPACE 0x1FFF

void memory_init(void);
uint8_t memory_read(uint16_t address);
void memory_write(uint16_t address, uint8_t value, bool isprivileged);

#endif
