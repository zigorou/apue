VPATH = ../lib ../include
CC = gcc
CPPFLAGS = -Wall -I../include
TARGETS = myls mycat getcputc hello
OBJECTS = error.o myls.o mycat.o getcputc.o hello.o

all: $(TARGETS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGETS)

error.o: error.h

myls: myls.o error.o
myls.o: error.h

mycat: mycat.o error.o
mycat: error.h

getcputc: getcputc.o error.o
getcputc.o: error.h

hello: hello.o
hello.o:

shell1: shell1.o error.o
shell1.o: error.h
