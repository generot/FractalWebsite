CC=gcc
CASM=masm
CFLAGS= -Wall

d.exe: d.o m.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

%.o: %.asm
	$(CASM) /Fo $@ /c $<

.PHONY: clean

clean:
	del *.o d.exe