CPP=g++
CFLAGS= -g -Wall -L.
LIB= -lmylib
DEPS= head2.h

ant.exe: ant.o $(LIB)
	$(CPP) $(CFLAGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CPP) $(CFLAGS) -c $<

.PHONY: clean

clean:
	del *.o ant.exe