all: pratica.o lista.o
	@gcc pratica.o lista.o -o programa -g -Wall
pratica.o: pratica.c
		@gcc pratica.c -c -g -Wall
lista.o: lista.c
	@gcc lista.c -c -g -Wall
run:
	@./programa
