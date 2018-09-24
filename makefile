# Author: Alex St. Clair
# Created: 9-24-2018
#
# With inspiration from the following tutorial:
# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC=gcc
CFLAGS= -Wall -Wextra
OBJECTS= help_mem.o

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

mem_manip: main.c $(OBJECTS)
	$(CC) -o mem_manip main.c $(OBJECTS) $(CFLAGS)

clean:
	rm mem_manip
	rm *.o