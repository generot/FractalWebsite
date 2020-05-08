CC=gcc
CFLAGS= -g -Wall

main.exe: main.o
	$(CC) $(CFLAGS) -o main.exe main.o

main.o: main.c head.h
	$(CC) $(CFLAGS) -c main.c

clean:
	del *.o