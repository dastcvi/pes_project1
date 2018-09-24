CC=gcc
CFLAGS= -Wall -Wextra
OBJECTS= help_mem.o
HEADERS= help_mem.h

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

mem_manip: main.c $(OBJECTS)
	$(CC) -o mem_manip main.c $(OBJECTS) $(CFLAGS)

clean:
	rm mem_manip
	rm *.o