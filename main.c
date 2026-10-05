#include <stdio.h>
#include <stdbool.h>
#include "src/includes/cpu.h"
#include "src/includes/ram.h"
#include "src/includes/logger.h"

int main(void)
{
	init_cpu();
	memory_init();

	my_logger.info = "INFO";
	my_logger.debug = "DEBUG";
	my_logger.is_authorized = true;
	printf("System Initialized with Sucess\n");
}
