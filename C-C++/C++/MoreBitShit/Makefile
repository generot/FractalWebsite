CPP=g++
CFLAGS= -g -Wall
DEPS= classes.h
STD= -std=c++11

pr.exe: xnxx.o ph.o
	$(CPP) $(CFLAGS) -o $@ $^ $(STD)

%.o: %.cpp $(DEPS)
	$(CPP) $(CFLAGS) -c $< $(STD)

.PHONY: clean

clean:
	del *.o pr.exe