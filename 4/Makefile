VPATH = ../lib ../include
CC = gcc
CPPFLAGS = -Wall -I../include
TARGETS = filetype
OBJECTS = filetype.o error.o

all: $(TARGETS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGETS)

error.o: error.h
path_alloc.o: path_alloc.h error.h
open_max.o: open_max.h error.h

filetype: filetype.o error.o
filetype.o: error.h
