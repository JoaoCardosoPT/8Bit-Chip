#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "../includes/instructions.h"
void dissasemble(const uint8_t *code, size_t size)
{
    size_t count = sizeof instructions / sizeof instructions[0];
    size_t pc = 0;

    while (pc < size)
    {
        const Instructions *inst = NULL;

        for (size_t i = 0; i < count; i++)
        {
            if (instructions[i].opcode == code[pc])
            {
                inst = &instructions[i];
                break;
            }
        }

        if (inst == NULL)
        {
            printf("DV 0x%02X\n", (unsigned)code[pc]);
            pc++;
            continue;
        }

        // Check that the complete instruction fits in the input, Ex: Load_R0 Requires an opcode and Operand
        if ((size_t)inst->size > size - pc)
        {
            printf("DB 0x%02X ; incomplete %s\n", (unsigned)code[pc], inst->name);
            break;
        }

        printf("%s", inst->name);

        if (inst->size == 2)
        {
            printf(" %u", (unsigned)code[pc + 1]);
        }

        printf("\n");
        pc += (size_t)inst->size;
    }
}
