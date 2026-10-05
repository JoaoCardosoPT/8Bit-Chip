#include <stdbool.h>
#include <stdio.h>

#include "../includes/logger.h"

log_levels my_logger = {
	.info = "INFO", 
	.trace = "TRACE", 
	.debug = "DEBUG", 
	.is_authorized = true
};

void log_status(const char *message)
{
	if (my_logger.is_authorized)
		return ;
	printf("[%s] %s\n", my_logger.info, message);
}
