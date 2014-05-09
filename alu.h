#ifndef __ALU_H__
#define __ALU_H__

#include "dateu.h"

int alu_mov(dinst_t *dinst);
int alu_add(dinst_t *dinst);
int alu_sub(dinst_t *dinst);
int alu_mul(dinst_t *dinst);
int alu_div(dinst_t *dinst);
int alu_not(dinst_t *dinst);
int alu_and(dinst_t *dinst);
int alu_or(dinst_t *dinst);
int alu_xor(dinst_t *dinst);
int alu_b(dinst_t *dinst);
int alu_ldr(dinst_t *dinst);
int alu_cmp(dinst_t *dinst);

#endif