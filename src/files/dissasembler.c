#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

void dissasemble(const uint8_t *code, size_t size)
{
	size_t pc = 0;
	while (pc < size)
	{
		printf("%04zX: ", pc);
		uint8_t opcode = code[pc];
		switch (opcode)
		{
			case 0x00:
				printf("HALT\n");
				// Instructions ocupies 1 byte
				pc++;
				break;
			case 0x01:
			case 0x02:
				// how many bytes are left, including the byte at the position
				if (size - pc < 2)
				{
					printf("DB 0x%02X: argument miss\n", (unsigned)opcode);
					pc++;
					break;
				}
				printf("LOAD_R%u %u\n", (unsigned)(opcode - 0x01), (unsigned)code[pc + 1]);
				pc += 2;
				break;
			case 0x10:
				printf("ADD\n");
				pc++;
				break;
			default:
				printf("Unknown Opcode\n");
				pc++;
				break;
		}	
	}	
}
