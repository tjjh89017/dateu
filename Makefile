PROG = dateu

CC = gcc

CFLAGS = -Wall -Wextra \
	-std=gnu99
LIBS = -levent_pthreads -levent -lpthread
LDFLAGS = 

OBJS = \
	alu.o \
	memory.o \
	init.o \
	pipeline.o \
	main.o

.c.o:
	$(CC) $(CFLAGS) -c $*.c

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(CFLAGS) $(OBJS) $(LIBS) $(LDFLAGS)

clean:
	rm -f $(PROG) $(OBJS)

debug: $(PROG)
	gdb ./$(PROG)	
