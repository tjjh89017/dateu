#include "alu.h"

extern int mem_read();
extern int mem_write();

static int address_mode(flag_t FLAG, operand_t R, operand_t **operand, reg_t *imm)
{
	switch(FLAG){
		case FLAG_IMME_MODE:
			*imm = R;
			*operand = imm;
			break;
		case FLAG_REG_MODE:
			*operand = &reg[R];
			break;
		case FLAG_DIR_MODE:
			MEM_ADR = R;
			mem_read();
			break;
		case FLAG_REGI_MODE:
			MEM_ADR = reg[R];
			mem_read();
			break;
	}
	return (int)FLAG;
}

int mov(flag_t FLAG, reg_t RT, reg_t RS)
{
	/* check for operand0 addressing mode */
	reg_t *operand0 = NULL, *operand1 = NULL;
	address_mode((FLAG & FLAG_OPERAND0_MASK) >> FLAG_OPERAND0_SH, RT, &operand0, &IMM_0);
	address_mode((FLAG & FLAG_OPERAND1_MASK) >> FLAG_OPERAND1_SH, RS, &operand1, &IMM_1);

	/* do inst */
	*operand0 = *operand1;

	if(((FLAG & FLAG_OPERAND1_MASK) >> FLAG_OPERAND1_SH) & 0x02)
		mem_write();
}