CC=g++
CFLAGS= -g -Wall
HEAD=smth.h

s.exe: smth.o smth2.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HEAD)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	del *.o s.exe