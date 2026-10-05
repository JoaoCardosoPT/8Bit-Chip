#ifndef CPU_H
#define CPU_H

#include <stdint.h>

// the cpu will have the registers inside his core
typedef enum {
	R0, R1, R2, R3, R4, R5, R6, R7
} registers;

typedef struct {
	uint8_t registers[8];
	uint16_t pc;
	bool is_running;
	bool is_priveleg;
} CPU;

extern CPU my_cpu;
void init_cpu(void);
#endif
