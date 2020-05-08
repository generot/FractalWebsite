CC=gcc
CFLAGS= -g -Wall
DEPS=head.h

a.exe: 1.o 2.o
	$(CC) $(CFLAGS) -o a.exe $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	del *.o a.exe