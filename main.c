#include "dateu.h"

int main()
{
	memory_init();
	register_init();

	unsigned int a = 0x87654321;
	MEM_ADR = 0;
	MEM_VALUE = a;

	mem_write();

	inst_t inst;
	fetch_inst(&inst);
}