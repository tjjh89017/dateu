#include "pipeline.h"

int address_mode(flag_t FLAG, operand_t R, operand_t **operand, reg_t *imm)
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

int fetch_stage(inst_t *inst)
{
	
}
/* decode the inst, find condition, load memory */
int decode_stage(inst_t *inst)
{

}
/* execute the inst, save value to register */
int exec_stage(dinst_t *dinst)
{

}
/* save MEM_VALUE into the memory */
int save_stage()
{

}

int pipeline_init()
{
	
}