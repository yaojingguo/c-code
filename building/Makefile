all: arith_main bad_arith_main add_main
		
clean:
	@rm -fr *.o *.so *_main

add.o: add.c
	cc -c -Wall -Werror -fpic $^ 

libadd.so: add.o
	cc -shared -o libadd.so $^

arith.o: arith.c
	cc -c -Wall -Werror -fpic arith.c

libarith.so: arith.o
	cc -shared -o libarith.so arith.o -undefined dynamic_lookup

libxxx.so: arith.o
	cc -shared -o libxxx.so arith.o

add_main:  add_main.c libadd.so
	cc -Wall -o $@ $< -ladd -L.

arith_main:     libarith.so arith_main.c libadd.so 
	cc -Wall -o $@ arith_main.c -larith -ladd -L.

bad_arith_main: libarith.so arith_main.c
	cc -Wall -o $@ arith_main.c -larith -L.
