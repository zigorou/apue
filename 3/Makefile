VPATH = ../lib ../include
CC = gcc
CPPFLAGS = -Wall -I../include
TARGETS = seek hole fileflags
OBJECTS = seek.o hole.o fileflags.o

all: $(TARGETS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGETS)

error.o: error.h
path_alloc.o: path_alloc.h error.h
open_max.o: open_max.h error.h

seek: seek.o

hole: hole.o error.o
hole.o: error.h

fileflags: fileflags.o error.o
fileflags.o: error.h
