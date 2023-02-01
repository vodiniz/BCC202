all:main.o lista.o
	@gcc main.o lista.o -o programa -g -Wall
main.o: main.c
		@gcc main.c -c -g -Wall
lista.o: lista.c
	@gcc lista.c -c -g -Wall
run:
	@./programa
