all: pratica.o ordenacao.o
	@gcc pratica.o ordenacao.o -o exe -g
	@rm -r *.o
pratica.o: pratica.c
	@gcc pratica.c -c -g
ordenacao.o: ordenacao.c
	@gcc ordenacao.c -c -g
run:
	@./exe
