# using gcc compiler
CC = gcc

# output path and filename
BINARY = ./ex01

# sources directory
# choose a file from the examples directory
SRC = ./ex01.c

# includes directory
INCLUDES = ./includes

# libraries and flags
LIBS = -lm
FLAGS = -Wall -O0 -g -Wextra -pthread

all: compile run clean

compile:
	$(CC) -o $(BINARY) -I$(INCLUDES) $(SRC) $(LIBS)

test:
	run clean debug

run:
	clear && $(BINARY)

debug:
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes $(BINARY)

clean:
	rm *.o
