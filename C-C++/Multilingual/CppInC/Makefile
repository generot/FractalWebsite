CC=gcc
CPP=g++
DEPS=funcs.h
CFLAGS= -Wall

app.exe: main.o utils.o
	$(CPP) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

%.o: %.cpp $(DEPS)
	$(CPP) $(CFLAGS) -c $<

.PHONY: clean

clean:
	del *.o