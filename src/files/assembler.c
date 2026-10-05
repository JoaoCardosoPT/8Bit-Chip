#include <stdio.h>
#include <string.h>
#include <stdint.h>

void assemble_line(const char *line, uint8_t *output_buffer, int *buffer_size)
{
	char command[20];
	int argument = 0;
	*buffer_size = 0;

	int items_parsed = sscanf(line, "%s %d", command, &argument);

	if (items_parsed <= 0)
		return;
	
	// We are just comparing if the command written is equal to the ones we have presset
	if(strcmp(command, "HALT") == 0)
	{
		output_buffer[0] = 0x00;
		*buffer_size = 1;
	}
	else if (strcmp(command, "LOAD_R0") == 0)
	{
		output_buffer[0] = 0x01;
		output_buffer[1] = (uint8_t)argument;
		*buffer_size = 2;
	}
	else if (strcmp(command, "LOAD_R1") == 0)
	{
		output_buffer[0] = 0x02;
        	output_buffer[1] = (uint8_t)argument;
        	*buffer_size = 2;
	}
	else if (strcmp(command, "ADD") == 0)
	{
		output_buffer[0] = 0x10;	
		*buffer_size = 1;
	}
}
