#include "dateu.h"

int main()
{
	memory_init();
	register_init();

	inst_t inst;
	fetch_inst(&inst);
	char *a = (char*)&inst;
	int i;
	for(i = 0; i < INST_LEN; i++){
		printf("%x ", a[i]);
	}
	puts("");

	return 0;
}