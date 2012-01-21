VPATH = ../lib ../include
CC = gcc
CPPFLAGS = -Wall -I../include
TARGETS = myls mycat getcputc hello testerror uidgid shell2
OBJECTS = error.o myls.o mycat.o getcputc.o \
          hello.o testerror.o uidgid.o shell2.o

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

testerror: testerror.o
testerror.o:

uidgid: uidgid.o
uidgid.o:

shell2: shell2.o error.o
shell2.o: error.h
