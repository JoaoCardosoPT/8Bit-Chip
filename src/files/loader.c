#include <stdbool.h>
#include <stdio.h>

#include "../includes/loader.h"
#include "../includes/ram.h"

bool load_program(const char *path, uint16_t start_address)
{
	FILE *file;

	file = fopen(path, "rb");

	if (file == NULL)
	{
		printf("File Opening Error");
		return false;
	}
	
	if (fseek(file, 0, SEEK_END) != 0)
	{
		fclose(file);
		return false;
	}

	long file_size = ftell(file);
	if (file_size > RAM_SIZE - start_address || file_size <= 0)
	{
		fclose(file);
		return false;
	}
	if (fseek(file, 0, SEEK_SET) != 0)
	{
		fclose(file);
		return false;
	}
	for (size_t i = 0; i < (size_t)file_size; i++)
	{
		// reach index by index
		int byte = fgetc(file);
		if (byte == EOF)
		{
			fclose(file);
			return false;
		}
		// the cast converts to the espected type for each position
		memory_write((uint16_t)(start_address + i), (uint8_t)byte, true);
	}
	
	fclose(file);
	return true;	
}
