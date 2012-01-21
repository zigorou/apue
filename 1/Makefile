VPATH = ../lib
CC = gcc
CPPFLAGS = -Wall -I../lib
TARGETS = myls
OBJECTS = error.o myls.o

all: $(TARGETS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGETS)

error.o: error.h

myls: myls.o error.o
myls.o: error.h

