all:
	gcc -c lib.c
	gcc -c main.c
	gcc main.o lib.o -o a.out
	objdump -S main.o > main.S
	objdump -S lib.o > lib.S
	objdump -S a.out > a.out.S

clean:
	rm *.S *.o a.out
