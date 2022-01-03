CC = gcc
FLAGS = -Wall -g
AR= ar


#make all
all: graph



graph: main.o graph.o
	$(CC) main.o graph.o -o graph

main.o: main.c graphNew.h
	$(CC) $(FLAGS) -c main.c

graph.o: graph.c graphNew.h
	$(CC) $(FLAGS) -c graph.c

#make clean
.PHONY: clean all

 clean:
	rm -f graph *.o