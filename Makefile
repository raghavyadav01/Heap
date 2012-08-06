CC:=gcc
CFLAGS=-c  -g -w
LDFLAGS= 
SOURCES= minHeap.c heap.h test.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=minHeap

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

install:
	cp -f minHeap /usr/local/bin
clean:
	rm -f *~
	rm -f *.o
	rm -f minHeap
