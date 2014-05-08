#include "alu.h"

extern int mem_read();
extern int mem_write();

void alu_mov(dinst_t *dinst)
{
	/* do inst */
	*dinst->operand[0] = *dinst->operand[1];
}