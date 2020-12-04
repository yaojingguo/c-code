all:
	gcc -c one.c two.c main.c
	gcc --shared -o libtwo.so two.o
	gcc -o two main.o -Wl,-rpath . -L. -ltwo one.o
	./two

clean: 
	@rm -fr *o *.so main

