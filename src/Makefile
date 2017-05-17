CC = gcc
RM = rm -f    
MKDIR = mkdir -p
RMDIR = rm -rf
LDFLAGS = -shared    
CFLAGS = -O0 -g -fPIC -I../include/

TARGET_LIB = ../lib/libheap.so    
    
SRCS = heap.c utils.c minHeap.c maxHeap.c
OBJS = $(SRCS:.c=.o)    
    
.PHONY: all    
all: ${TARGET_LIB}    
    
$(TARGET_LIB): $(OBJS)    
	$(MKDIR) ../lib
	$(CC) ${LDFLAGS} -o $@ $^                 
    
$(SRCS:.c=.d):%.d:%.c    
	$(CC) $(CFLAGS) -MM $< >$@                
    
include $(SRCS:.c=.d)    
    
.PHONY: clean
clean:                                            
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)
	-${RMDIR} ../lib

