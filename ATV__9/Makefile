BINARY=exe
INPUT = in.in

all:
	gcc -O3 -march=native -g main.c quick_Sort.c -o $(BINARY) -lm

run:
	./$(BINARY)

input:
	./$(BINARY) < $(INPUT) > out.txt

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)