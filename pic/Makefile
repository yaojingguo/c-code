all:
	gcc -c -fPIC mylib.c
	gcc -shared -o libmylib.so mylib.o
	gcc -c main.c
	gcc main.o -L`pwd` -lmylib

clean:
	rm *.o *.so a.out
