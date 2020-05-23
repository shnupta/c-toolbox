CC	=	gcc
CFLAGS	=	-Wall
LIB     =       lib/toolkit.a
LIBOBJS	=	src/log.o src/test.o
BUILD	=	$(LIB)

all:	$(BUILD)

clean:
	rm -f lib/* src/*.o 

$(LIB): $(LIBOBJS)
	ar rcs $(LIB) $(LIBOBJS)
	ranlib $(LIB)

src/log.o: src/log.h

src/test.o: src/test.h
