CC=g++
CFLAGS= -g -Wall

t.exe: c++.o
	$(CC) $(CFLAGS) -o $@ $<

c++.o: c++.cpp defs.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	del *.o t.exe