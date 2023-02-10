all: pratica.o lista.o pilha.o fila.o
	@gcc pratica.o lista.o pilha.o fila.o -o exe -g
	@rm -r *.o
pratica.o: pratica.c
	@gcc pratica.c -c -g
lista.o: lista.c
	@gcc lista.c -c -g
pilha.o: pilha.c
	@gcc pilha.c -c -g
fila.o: fila.c
	@gcc fila.c -c -g
run:
	@./exe
