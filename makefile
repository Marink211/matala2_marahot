
CC = gcc
FLAGS = -Wall -g

all : progmains

progmains : main.o myBank.o
	        $(CC) $(FLAGS) -o progmains main.o myBank.o

main.o : main.c myBank.h
	        $(CC) $(FLAGS) -c main.c
myBank.o : myBank.c myBank.h
	        $(CC) $(FLAGS) -c myBank.c







.PHONY : clean

clean :
	        rm -f *.o *.a *.so
		~
