#ifndef __ALU_H__
#define __ALU_H__

#include "dateu.h"

int alu_mov(inst_t *inst);
int alu_add(inst_t *inst);
int alu_sub(inst_t *inst);
int alu_mul(inst_t *inst);
int alu_div(inst_t *inst);
int alu_not(inst_t *inst);
int alu_and(inst_t *inst);
int alu_or(inst_t *inst);
int alu_xor(inst_t *inst);
int alu_b(inst_t *inst);
int alu_ldr(inst_t *inst);
int alu_cmp(inst_t *inst);

#endif