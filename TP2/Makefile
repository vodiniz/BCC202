all: pratica.o ordenacao.o compare_double.o
	@gcc tp.o ordenacao.o compare_double.o -o exe -g -Wall -lm
	@rm -r *.o
pratica.o: tp.c
	@gcc tp.c -c -g -lm
ordenacao.o: ordenacao.c 
	@gcc ordenacao.c -c -g -lm -Wall
compare_double.o: compare_double.c
	@gcc compare_double.c -c -g -lm -Wall
run:
	@./exe
