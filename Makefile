CC = gcc
CFLAGS = -Wall -g -lpthread -fsanitize=address

all : proc thread

proc : searchtest multiproc

searchtest: searchtest.c
	$(CC) $(CFLAGS) -o search searchtest.c 
multiproc: searchtest.c
	$(CC) $(CFLAGS) -o search searchtest.c 


thread : searchtest.c multithread.c
	$(CC) $(CFLAGS) -o proc multithread.c

