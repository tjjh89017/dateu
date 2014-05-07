#include "dateu.h"

int memory_init()
{
	memory = fopen(DEVICE MEMORY, "rb+");

	return 0;
}

int register_init()
{
	memset(reg, 0, REG_LEN * sizeof(reg_t));

	return 0;
}