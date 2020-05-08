CC=gcc
CFLAGS= -Wall
DEP= head.h

b.exe: window.o tools.o
	$(CC) $(CFLAGS) -o $@ $^ -lGdi32

%.o: %.c $(DEP)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	del *.o