#include "alu.h"

extern int mem_read();
extern int mem_write();

int alu_mov(dinst_t *dinst)
{
	/* do inst */
	*dinst->operand[0] = *dinst->operand[1];
	return 0;
}

int alu_add(dinst_t *dinst)
{
	*dinst->operand[0] = *dinst->operand[1] + *dinst->operand[2];
	/* set flag */
	return 0;
}

int alu_sub(dinst_t *dinst)
{
	*dinst->operand[0] = *dinst->operand[1] - *dinst->operand[2];
	/* set flag */
	return 0;
}

int alu_mul(dinst_t *dinst)
{
	*dinst->operand[0] = *dinst->operand[1] * *dinst->operand[3];
	/* we have to save the value into another register */
	return 0;
}

int alu_div(dinst_t *dinst);
int alu_not(dinst_t *dinst);
int alu_and(dinst_t *dinst);
int alu_or(dinst_t *dinst);
int alu_xor(dinst_t *dinst);
int alu_b(dinst_t *dinst);
int alu_ldr(dinst_t *dinst);
int alu_cmp(dinst_t *dinst);