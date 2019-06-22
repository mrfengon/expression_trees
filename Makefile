CC = gcc

CCFLAGS = -g

OBJ = tree.o functions.o main.o

.SUFFIXES: .c .o

main: $(OBJ)
	@$(CC) $(CCFLAGS) $(OBJ) -o main

main.o: funcs.o sort.o
	$(CC) -c $(CCFLAGS) main.c

functions.o: functions.h
	$(CC) -c $(CCFLAGS) functions.h

tree.o: tree.h
	$(CC) -c $(CCFLAGS) tree.h

clean:
	@rm -f *.o *.gch main