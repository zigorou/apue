VPATH = ../lib ../include
CC = gcc
CPPFLAGS = -Wall -I../include
TARGETS = filetype access umask changemod
OBJECTS = filetype.o access.o umask.o changemod.o error.o
FILES   = foo bar

all: $(TARGETS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGETS)
	$(RM) $(FILES)

error.o: error.h
path_alloc.o: path_alloc.h error.h
open_max.o: open_max.h error.h

filetype: filetype.o error.o
filetype.o: error.h

access: access.o error.o
access.o: error.h

umask: umask.o error.o
umask.o: error.h

changemod: changemod.o error.o
changemod.o: error.h