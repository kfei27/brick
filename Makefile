#
# Brick Makefile.
#
# Revision:
# 20110503  File creation.

LDFLAGS :=
# OpenGL
LDFLAGS += -L /lib/w32api
LDFLAGS += -lopengl32
LDFLAGS += -lgdi32
LDFLAGS += -lglu32
# Mingw
LDFLAGS += -L /lib/mingw
LDFLAGS += -lmingw32
#LDFLAGS +=  -Xlinker -I -Xlinker /lib/mingw
LDFLAGS += -Wl,-I,/lib/mingw

CPPFLAGS :=
#CPPFLAGS += -I /usr/include/w32api

CC :=
CC += g++
# Use OS-supplied runtime.
CC += -mno-cygwin

# Optimization
CFLAGS :=
# Produce debugging information
CFLAGS += -g 
# Do not optimize
#CFLAGS += -O0
# Optimize even more
#CFLAGS += -O2
# Optimize yet more
#CFLAGS += -O3
# Optimize for size
#CFLAGS += -Os
# Verbose
#CFLAGS += -v 

PROGS = \
    brick

all: $(PROGS)

.c.o:
	$(CC) $(CFLAGS) -c $*.c

.SUFFIXES: .c .o

brick : main.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

main.o : main.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY : clean dependencies

clean:
	$(RM) $(PROGS) *.o *.gch

dependencies:
#To see what DLLs it's using:
	objdump -p $(PROGS) | grep "DLL Name"
