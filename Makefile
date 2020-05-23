CC	=	gcc
CFLAGS	=	-Wall
LDLIBS	=	-llog
LIB     =       lib/log.a
LIBOBJS	=	src/log.o
BUILD	=	$(LIB)

all:	$(BUILD)

clean:
	rm -f lib/* src/*.o 

$(LIB): $(LIBOBJS)
	ar rcs $(LIB) $(LIBOBJS)

src/log.o: src/log.h
