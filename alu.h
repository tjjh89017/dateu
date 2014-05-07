#ifndef __ALU_H__
#define __ALU_H__

#include "dateu.h"

int mov(inst_t *inst);
int add(inst_t *inst);
int sub(inst_t *inst);
int mul(inst_t *inst);
int div(inst_t *inst);
int not(inst_t *inst);
int and(inst_t *inst);
int or(inst_t *inst);
int xor(inst_t *inst);
int b(inst_t *inst);
int ldr(inst_t *inst);
int cmp(inst_t *inst);

#endif