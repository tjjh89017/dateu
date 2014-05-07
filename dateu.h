#ifndef __DATEU_H__
#define __DATEU_H__

typedef unsigned char op_t;
typedef unsigned char cond_t;
typedef unsigned short flag_t;
typedef unsigned int reg_t;
typedef unsigned int mem_t;

typedef union
{
	reg_t reg;
	mem_t mem;
}operand_t;

typedef struct
{
	op_t op_code;
	cond_t cond;
	flag_t flag;
	operand_t operand[3];
}inst_t;

#define DEVICE "device/"
#define MEMORY "memory"

/* define instruction */
/* program end */
#define END ((unsigned char)0x00)
/* save or load value into register or memory */
#define MOV ((unsigned char)0x01)
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


#endif