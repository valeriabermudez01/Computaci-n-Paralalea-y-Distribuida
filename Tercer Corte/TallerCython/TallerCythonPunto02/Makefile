GCC = gcc 
FLAGS = -pedantic -Wall
CFLAGS = -lm -pthread

PROGS: main

main:
	$(GCC) $(FLAGS) cfib.c -c
	$(GCC) $(FLAGS) $@.c -c 
	$(GCC) $(FLAGS) cfib.o $@.o -o $@	

clean:
	$(RM) $(PROGS) *.o
