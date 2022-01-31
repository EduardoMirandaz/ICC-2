BINARY=exe
INPUT = "10.in"

all:
	gcc -O3 -march=native -Wall -g main.c dots.c -o $(BINARY) -lm

run:
	./$(BINARY)

input:
	$(BINARY) < $(INPUT)

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)