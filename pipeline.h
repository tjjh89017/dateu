#ifndef __PIPELINE_H__
#define __PIPELINE_H__

#include "dateu.h"

int address_mode(flag_t FLAG, operand_t R, operand_t **operand, reg_t *imm);


/* we don't use the RISC's 5 stage pipeline */
/* fetch the code */
int fetch_stage(inst_t *inst);
/* decode the inst, find condition, load memory */
int decode_stage(inst_t *inst);
/* execute the inst, save value to register */
int exec_stage(dinst_t *dinst);
/* save MEM_VALUE into the memory */
int save_stage();

int pipeline_init();

#endif