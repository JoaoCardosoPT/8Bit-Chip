#include <stdio.h>
#include <stdbool.h>
#include "src/includes/cpu.h"
#include "src/includes/ram.h"
#include "src/includes/logger.h"
#include "src/includes/loader.h"
#include "src/includes/cpu_exec.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	init_cpu();
	memory_init();

	my_logger.info = "INFO";
	my_logger.debug = "DEBUG";
	my_logger.is_authorized = true;
	printf("System Initialized with Sucess\n");
	memory_init();
	// 0x0000 == initial value of pc
	if (!load_program(argv[1], 0x0000))
		return 1;
	
	while(my_cpu.is_running)
	{
		execute_next_instructions();
	}
	printf("R0 = %u\n", (unsigned)my_cpu.registers[R0]);
}
