#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "dateu.h"

int mem_read();
int mem_write();

int fetch_inst(inst_t &inst);

#endif