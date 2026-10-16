#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include "instructions.h"
#include "assembler.h"

void assemble_line(const char *line, uint8_t *output_buffer, int *buffer_size)
{
	char command[20];
	// first argument as text
	char argument_text[64];
	int argument = 0;
	*buffer_size = 0;

	// delimit to 19 characters
	int items_parsed = sscanf(line, "%19s %d", command, argument_text);

	if (items_parsed <= 0)
		return;

	// We removed the if else statments and created a structure for instructions
	size_t count = sizeof instructions / sizeof instructions[0];
	for (size_t i = 0; i < count; i++)
	{
		if (strcmp(command, instructions[i].name) != 0)
			continue;

		output_buffer[0] = instructions[i].opcode;

		if (instructions[i].size == 2)
		{
			if (items_parsed != 2)
			{
				printf("lacks argument");
				return;
			}

			char *end;
			errno = 0;

			long value = strtol(argument_text, &end, 10);

			if (end == argument_text)
			{
				printf("The arg is not a number\n");
				return;
			}

			if (*end != '\0')
			{
				printf("Argument contains invalid chars\n");
				return;
			}

			if (errno == ERANGE || value < 0 || value > 255)
			{
				printf("Argument must be between 0 and 255");
				return;
			}

			// Converts to 8 bits withouth signal (0 - 255)
			argument = (uint8_t)value;
		}

		*buffer_size = instructions[i].size;
		return;
	}
}
