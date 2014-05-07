PROG = dateu

CC = gcc

CFLAGS = -Wall -Wextra \
	-std=gnu99
LIBS = 
LDFLAGS = 

OBJS = \
	alu.o \
	memory.o \
	init.o \
	main.o

.c.o:
	$(CC) $(CFLAGS) -c $*.c

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(CFLAGS) $(OBJS) $(LIBS) $(LDFLAGS)

clean:
	rm -f $(PROG) $(OBJS)
