CC = gcc

CCFLAGS = -g

OBJ = tree.o main.o

.SUFFIXES: .c .o

main: $(OBJ)
	@$(CC) $(CCFLAGS) $(OBJ) -o main

main.o: tree.o
	$(CC) -c $(CCFLAGS) main.c

tree.o: tree.h tree.c
	$(CC) -c $(CCFLAGS) tree.h tree.c

clean:
	@rm -f *.o *.gch main