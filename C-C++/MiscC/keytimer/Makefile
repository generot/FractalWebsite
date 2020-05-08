CC=gcc
CFLAGS= -g -Wall
DEPS=tools.h dictionary.txt

k.exe: keytimer.o
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	del *.o k.exe