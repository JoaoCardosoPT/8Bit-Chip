#include <stdbool.h>
#include "../includes/cpu.h"

CPU *my_cpu;

// Reset the CPU in inicialization
void init_cpu(void)
{
	for (int i = 0; i < 8; i++)
		my_cpu->registers[i] = 0;	
	
	my_cpu->pc = 0x000;
	my_cpu->is_running = true;
	my_cpu->is_priveleg = true;
}
