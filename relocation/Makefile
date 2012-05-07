all:
	gcc -c lib.c
	gcc -c main.c
	gcc main.o lib.o -o prog
	objdump -S main.o > main.S
	objdump -S lib.o > lib.S
	objdump -S prog > prog.S

clean:
	rm *.S *.o
