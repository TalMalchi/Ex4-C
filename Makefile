CC = gcc
FLAGS = -Wall -g
AR= ar


#make all
all: graph

#make clean
.PHONY: clean all

 clean:
	rm -f graph *.o