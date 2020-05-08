CC=gcc
CFLAGS= -Wall -g
DEPS= utilities.h

BInt.exe: binter.o impl.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean st

clean:
	del *.o

st:
	strip BInt.exe
	