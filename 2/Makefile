VPATH = ../lib ../include
CC = gcc
CPPFLAGS = -Wall -I../include
TARGETS = sysconfpathconf
OBJECTS = sysconfpathconf.o error.o path_alloc.o open_max.o

all: $(TARGETS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGETS)

error.o: error.h
path_alloc.o: path_alloc.h error.h
open_max.o: open_max.h error.h

sysconfpathconf: sysconfpathconf.o error.o
sysconfpathconf.o: error.h

dynamiclimit: dynamiclimit.o path_alloc.o open_max.o error.o
dynamiclimit: path_alloc.h open_max.h