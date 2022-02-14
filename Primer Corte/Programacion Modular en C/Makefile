GCC = gcc
FLAGS = -ansi -pedantic -Wall
CFLAGS = 

PROGS = principal 

principal:
	$(GCC) $(FLAGS) funciones.c -c
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) -o $@ funciones.o $@.o

clean:
	$(RM) $(PROGS) *.o
