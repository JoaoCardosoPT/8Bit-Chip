#include "../includes/ram.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

static uint8_t ram[RAM_SIZE];

// initialize the RAM at 0
void memory_init(void)
{
	for (int i = 0; i < RAM_SIZE; i++)
		ram[i] = 0;
}

// read byte of the address of the ram
uint8_t memory_read(uint16_t address)
{
	return ram[address];
}

void memory_write(uint16_t address, uint8_t value, bool isprivileged)
{
	if (address <= KERNEL_SPACE && !isprivileged)
	{
		printf("ERROR: Privilege Violation");
		return;
	}
	// if its safe
	ram[address] = value;
}


