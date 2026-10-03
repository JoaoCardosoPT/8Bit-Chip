#include "../includes/cpu_exec.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

CPU *my_cpu;

void execute_next_instructions(void)
{
	uint8_t opcode = memory_read(my_cpu->pc);
	my_cpu->pc++;
	
	// Opcode Defined By Me
	switch (opcode) {
		case 0x00:
			my_cpu->is_running = false;
			break;
		case 0x01:
			my_cpu->registers[R0] = memory_read(my_cpu->pc);
			my_cpu->pc++;
			break;
		case 0x02:
			my_cpu->registers[R1] = memory_read(my_cpu->pc);
			my_cpu->pc++;
			break;
		// Arithmetic
		case 0x10:
			my_cpu->registers[R0] = my_cpu->registers[R0] + my_cpu->registers[R1];
			break;
		default:
			printf("Error: Invalid Opcode!\n");
			my_cpu->is_running = false;
			break;
	}
}


