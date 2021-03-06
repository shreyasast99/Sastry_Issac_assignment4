CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -c -std=c++14 $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile: Main.out

Main.out: Main.o ItemType.o BinaryTree.o
	$(CC) $(LFLAGS) -o Main.out ItemType.o BinaryTree.o Main.o

Main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp

ItemType.o: ItemType.cpp ItemType.h
	$(CC) $(CFLAGS) ItemType.cpp

CircularLinkedList.o: BinaryTree.cpp BinaryTree.h ItemType.h
	$(CC) $(CFLAGS) BinaryTree.cpp

run: Main.out
	./Main.out BinaryTree/input.txt

clean:
	rm *.o Main.out
