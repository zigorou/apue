VPATH = ../lib ../include
CC = gcc
CPPFLAGS = -Wall -I../include
TARGETS = filetype access umask
OBJECTS = filetype.o access.o umask.o error.o

all: $(TARGETS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGETS)

error.o: error.h
path_alloc.o: path_alloc.h error.h
open_max.o: open_max.h error.h

filetype: filetype.o error.o
filetype.o: error.h

access: access.o error.o
access.o: error.h

umask: umask.o error.o
umask.o: error.h