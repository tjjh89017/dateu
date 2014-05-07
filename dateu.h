#ifndef __DATEU_H__
#define __DATEU_H__

#include <stdio.h>
#include <stdlib.h>

#include "init.h"

/* device path and filename */
#define DEVICE "./device/"
#define MEMORY "memory"

typedef unsigned char op_t;
typedef unsigned char cond_t;
typedef unsigned short flag_t;
typedef unsigned int reg_t;
typedef unsigned int mem_t;
typedef unsigned int operand_t;


typedef struct
{
	op_t op_code;
	cond_t cond;
	flag_t flag;
	operand_t operand[3];
}inst_t;

#define INST_LEN 16
#define REG_LEN  25

extern FILE *memory;
extern reg_t reg[REG_LEN];
extern mem_t inst_cache[16 * INST_LEN];

/* define special register name */
/* program counter */
#define PC        (reg[13])
/* stack pointer */
#define SP        (reg[14])
/* stack bottom pointer */
#define SBP       (reg[15])
/* flags */
#define FLAGS     (reg[16])
/* immediate value to put */
#define IMM_0     (reg[17])
#define IMM_1     (reg[18])
#define IMM_2     (reg[19])
/* direct or reg indirect addressing mode */
/* for address to write value */
#define MEM_ADR   (reg[20])
/* value to write */
#define MEM_VALUE (reg[21])

/* define condition bits and mask */
/*
	use: (x & COND_XXX_MASK) to check
    8 bits
    7 - 0
    
    (7) = 1 do it when zero flag
          0 do it when NOT zero flag
    (6) = 1 do it when neg flag
          0 do it when NOT neg flag
    (5) = 1 do it when carry flag
          0 do it when NOT carry flag
    (4) = 1 do it when overflow flag
          0 do it when NOT overflow flag
    (3)
    (2)
    (1) 
    (0) = always do flag
*/
/* always mask */
#define COND_ALW_MASK  ((unsigned char)0x01)
/* zero mask */
#define COND_ZERO_MASK ((unsigned char)0x80)
/* neg mask */
#define COND_NEG_MASK  ((unsigned char)0x40)
/* carry mask */
#define COND_CAR_MASK  ((unsigned char)0x20)
/* overflow mask */
#define COND_OVF_MASK  ((unsigned char)0x10)
/* equ cond */
#define COND_EQU_FLAG  ((unsigned char)0x80)

/* define inst flag bit and mask */
/*
	use: (x & FLAG_OPERAND0_MASK) to check mode
    16 bits
    15 - 0

    (15, 14) = operand 0 is immedite when eq 00
                            register when eq 01
                            direct addressing eq 10
                            register indirect addressing eq 11
    (13, 12) = operand 1
    (11, 10) = operand 2
*/
/* operand 0 mask */
#define FLAG_OPERAND0_MASK ((unsigned short)0xC000)
/* operand 1 mask */
#define FLAG_OPERAND1_MASK ((unsigned short)0x3000)
/* operand 2 mask */
#define FLAG_OPERAND2_MASK ((unsigned short)0x0C00)
/* mode */
#define FLAG_IMME_MODE     ((unsigned short)0x0000)
#define FLAG_REG_MODE      ((unsigned short)0x0001)
#define FLAG_DIR_MODE      ((unsigned short)0x0002)
#define FLAG_REGI_MODE     ((unsigned short)0x0003)
/* shift to cmp */
#define FLAG_OPERAND0_SH   ((unsigned short)0x000E)
#define FLAG_OPERAND1_SH   ((unsigned short)0x000C)
#define FLAG_OPERAND2_SH   ((unsigned short)0x000A)



/* define instruction */
/* program end */
#define END ((unsigned char)0x00)
/* nop */
#define NOP ((unsigned char)0x01)
/* save or load value into register or memory */
#define MOV ((unsigned char)0x02)
/* add two number */
#define ADD ((unsigned char)0x10)
/* sub two number */
#define SUB ((unsigned char)0x11)
/* mul two number */
#define MUL ((unsigned char)0x12)
/* div two number */
#define DIV ((unsigned char)0x13)
/* neg one number */
#define NOT ((unsigned char)0x20)
/* and two number */
#define AND ((unsigned char)0x21)
/* or two number */
#define OR  ((unsigned char)0x22)
/* xor two number */
#define XOR ((unsigned char)0x23)
/* branch for short jump */
#define B   ((unsigned char)0x30)
/* load address or for long jmup */
#define LDR ((unsigned char)0x31)
/* compare */
#define CMP ((unsigned char)0x40)


#endif