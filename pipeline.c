#include "pipeline.h"

#define STAGE_SIZE 4
#define FETCH_S 0
#define DECODE_S 1
#define EXEC_S 2
#define SAVE_S 3
void (*stage_cb[STAGE_SIZE])(evutil_socket_t, short, void*) = {
	fetch_stage,
	decode_stage,
	exec_stage,
	save_stage
};

stage_t *stages;

int address_mode(flag_t FLAG, operand_t R, operand_t **operand, reg_t *imm)
{
	switch(FLAG){
		case FLAG_IMME_MODE:
			*imm = R;
			*operand = imm;
			break;
		case FLAG_REG_MODE:
			*operand = &reg[R];
			break;
		case FLAG_DIR_MODE:
			MEM_ADR = R;
			mem_read();
			break;
		case FLAG_REGI_MODE:
			MEM_ADR = reg[R];
			mem_read();
			break;
	}
	return (int)FLAG;
}

void fetch_stage(evutil_socket_t fd, short what, void *arg)
{
	
}
/* decode the inst, find condition, load memory */
void decode_stage(evutil_socket_t fd, short what, void *arg)
{

}
/* execute the inst, save value to register */
void exec_stage(evutil_socket_t fd, short what, void *arg)
{

}
/* save MEM_VALUE into the memory */
void save_stage(evutil_socket_t fd, short what, void *arg)
{

}

static void persist_cb(int sock, short which, void *arg)
{
	struct event *ev = *(struct event**)arg;
	event_active(ev, EV_WRITE, 0);
}

static void* stage_begin(void *arg)
{
	printf("Stage begin\n");
	stage_t *s = (stage_t*)arg;

	s->base = event_base_new();
	s->persist_event = event_new(s->base, -1, EV_PERSIST | EV_READ, persist_cb, &s->persist_event);

	event_add(s->persist_event, NULL);
	event_base_dispatch(s->base);

	return NULL;
}

int pipeline_init()
{
	stages = (stage_t*)malloc(sizeof(stage_t) * STAGE_SIZE);

	pthread_mutex_t *mem_lock = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mem_lock, NULL);

	evthread_use_pthreads();

	int i = 0;
	for(i = 0; i < STAGE_SIZE; i++){
		stages[i].mem_lock = mem_lock;
		stages[i].callback = stage_cb[i];
		pthread_create(&stages[i].pid, NULL, stage_begin, &stages[i]);
	}
}