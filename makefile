all: GenericHashTable.c main.c
	g++ GenericHashTable.c main.c -o main
all-GDB:GenericHashTable.c main.c
	g++ GenericHashTable.c main.c -o main 	
