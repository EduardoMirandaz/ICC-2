BINARY=exe
INPUT = 20.in
## && ./$(BINARY) < $(INPUT)

all:
	gcc -O3 -march=native -g main.c operations.c -o $(BINARY) -lm

run:
	./$(BINARY)

input:
	./$(BINARY) < $(INPUT) > out.txt