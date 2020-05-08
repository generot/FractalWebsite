CC=gcc
CFLAGS= -g -Wall

client.exe: client.o
	$(CC) $(CFLAGS) -o $@ $< -lws2_32

client.o: client.c head.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	del *.o