CC = gcc
RM = rm -f    
LDFLAGS = -L../lib/ -lheap -Wl,-rpath,../lib/
CFLAGS = -O0 -g -I../include/ -I.

TARGET_BIN = testMinHeap testMaxHeap
    
#SRCS = test1.c
#OBJS = $(SRCS:.c=.o)
    
.PHONY: all
all: ${TARGET_BIN}
 
#$(TARGET_BIN): $(OBJS)
#	$(CC) -o $@ $^ $(LDFLAGS)

testMaxHeap: testMaxHeap.o utils.o test.o
	$(CC) -o testMaxHeap testMaxHeap.o utils.o test.o $(LDFLAGS)

testMaxHeap.o: testMaxHeap.c
	$(CC) $(CFLAGS) -c -o testMaxHeap.o testMaxHeap.c

testMinHeap: testMinHeap.o utils.o test.o
	$(CC) -o testMinHeap testMinHeap.o utils.o test.o $(LDFLAGS)

testMinHeap.o: testMinHeap.c
	$(CC) $(CFLAGS) -c -o testMinHeap.o testMinHeap.c

utils.o: utils.c
	$(CC) $(CFLAGS) -c -o utils.o utils.c

test.o: test.c
	$(CC) $(CFLAGS) -c -o test.o test.c

#$(SRCS:.c=.d):%.d:%.c
#	$(CC) $(CFLAGS) -MM $< >$@

#include $(SRCS:.c=.d)
    
.PHONY: clean
clean:
#	-${RM} ${TARGET_BIN} ${OBJS} $(SRCS:.c=.d)
	-${RM} ${TARGET_BIN} *.o
