BINARY=executavel
all:
	gcc -O3 -march=native -g -Wall -Werror -Wextra main.c shell.c quick.c -o $(BINARY) -lm
run:
	./$(BINARY)
valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)
input:
	./$(BINARY) < teste.in > out.txt
	