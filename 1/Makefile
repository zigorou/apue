VPATH = ../lib ../include
CC = gcc
CPPFLAGS = -Wall -I../include
TARGETS = myls mycat getcputc
OBJECTS = error.o myls.o mycat.o getcputc.o

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