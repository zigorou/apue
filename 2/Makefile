VPATH = ../lib ../include
CC = gcc
CPPFLAGS = -Wall -I../include
TARGETS = sysconfpathconf
OBJECTS = sysconfpathconf.o

all: $(TARGETS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGETS)

error.o: error.h

sysconfpathconf: sysconfpathconf.o error.o
sysconfpathconf.o: error.h
