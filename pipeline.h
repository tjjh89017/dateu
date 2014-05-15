#ifndef __PIPELINE_H__
#define __PIPELINE_H__

#include "dateu.h"

int address_mode(flag_t FLAG, operand_t R, operand_t **operand, reg_t *imm);

/* arg => inst_event_t* */
/* we don't use the RISC's 5 stage pipeline */
/* fetch the code */
void fetch_stage(evutil_socket_t fd, short what, void *arg);
/* decode the inst, find condition, load memory */
void decode_stage(evutil_socket_t fd, short what, void *arg);
/* execute the inst, save value to register */
void exec_stage(evutil_socket_t fd, short what, void *arg);
/* save MEM_VALUE into the memory */
void save_stage(evutil_socket_t fd, short what, void *arg);

int pipeline_init();

int pipeline_shutdown();

#endif