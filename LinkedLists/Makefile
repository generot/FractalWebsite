CC=gcc
CFLAGS= -g -Wall

list.exe: main.o
	$(CC) $(CFLAGS) -o list.exe main.o

main.o: main.c head.h
	$(CC) $(CFLAGS) -c main.c

clean:
	del *.o