#include "memory.h"

FILE *memory;
reg_t reg[REG_LEN];

int mem_read()
{
	char *buf = (char*)&MEM_VALUE;

	fseek(memory, MEM_ADR, SEEK_SET);
	fread(buf, 1, sizeof(reg_t), memory);

	return 0;
}

int mem_write()
{
	char *buf = (char*)&MEM_VALUE;

	fseek(memory, MEM_ADR, SEEK_SET);
	fwrite(buf, 1, sizeof(reg_t), memory);
}

int fetch_inst(inst_t *inst)
{
	char *buf = (char*)inst;

	fseek(memory, PC, SEEK_SET);
	fread(buf, 1, INST_LEN, memory);

	PC += INST_LEN;

	return 0;
}