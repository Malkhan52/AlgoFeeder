# Makefile to compile all files
CC = g++ # g++ compiler
CFLAGS = -std=c++14 # compiler flags
RM=rm # to clean build files
INC = -I /include/AlgoFeeder.h -I /include/gnuplot.h

insertionSort.out : insertionSort.o

	$(CC) $(CFLAGS) -o insertionSort.out insertionSort.o

insertionSort.o :
	$(CC) $(CFLAGS) -c ./src/insertionSort.cpp $(INC)

# to clean build files
clean:
	-@ $(RM) *.o
