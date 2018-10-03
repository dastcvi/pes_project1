# Author: Alex St. Clair
# Created: 9-24-2018
#
# With inspiration from the following tutorial:
# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC=gcc
CFLAGS= -Wall -Wextra
OBJECTS= alloc_mem.o display_mem.o free_mem.o help_mem.o invert_mem.o verify_pattern.o write_mem.o write_pattern.o

%.o: %.c ../inc/%.h
	$(CC) -c -o $@ $< $(CFLAGS)

mem_manip: main.c $(OBJECTS)
	$(CC) -o mem_manip main.c $(OBJECTS) $(CFLAGS)

test: mem_manip
	./mem_manip < testscript.txt

clean:
	rm mem_manip
	rm *.o