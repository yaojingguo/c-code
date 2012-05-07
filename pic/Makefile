all:
	gcc -c -fPIC mylib.c
	gcc -c -fPIC anotherlib.c
	gcc -shared -o libmylib.so mylib.o
	gcc -shared -o libanotherlib.so anotherlib.o
	gcc -c main.c
	objdump -S main.o > main.S
	objdump -S mylib.o > mylib.S
	gcc main.o -L`pwd` -lmylib -lanotherlib

clean:
	rm *.S *.o *.so a.out
