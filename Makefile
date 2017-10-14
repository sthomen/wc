#!smake
CC=cc
RM=rm -f
CFLAGS=-g
LDFLAGS=

SOURCES=wc.c

# select which one you wish to use

#SOURCES+=wc_array.c
SOURCES+=wc_pointer.c

OBJECTS=$(SOURCES:S/.c/.o/g)

PROGRAM=wc

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJECTS) $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) *.o
	$(RM) $(PROGRAM)
