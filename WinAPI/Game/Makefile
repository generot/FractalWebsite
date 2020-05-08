CC=gcc
CFLAGS= -Wall
DEPS= basehead.h
LIBS= -lGdi32

app.exe: base.o tools.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	del *.o