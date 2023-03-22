all: pratica.o avl.o
	@gcc pratica.o avl.o -o exe -g
	@rm *.o
pratica.o: pratica.c
		@gcc pratica.c -c -g
avl.o: avl.c
	@gcc avl.c -c -g
run:
	@./exe
