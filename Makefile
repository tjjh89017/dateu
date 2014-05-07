PROG = dateu

CC = gcc

CFLAGS = -Os -Wall -Wextra \
	-std=gnu99
LIBS = -levent_pthreads -levent -pthread
LDFLAGS = 

OBJS = 

.c.o:
	$(CC) $(CFLAGS) -c $*.c

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(CFLAGS) $(OBJS) $(LIBS) $(LDFLAGS)

clean:
	rm -f $(PROG) $(OBJS)
