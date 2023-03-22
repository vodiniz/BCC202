all: main.o ordenacao.o
	@gcc main.o ordenacao.o -o exe -g
	@rm -r *.o
main.o: main.c
	@gcc main.c -c -g
ordenacao.o: ordenacao.c
	@gcc ordenacao.c -c -g
run:
	@./exe
