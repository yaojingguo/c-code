all: main main2 main3 main4

main: 
	@rm -fr *.o *.po *.so
	@cc -g -c -o main.o main.c
	@cc -g -fpic -c -o power_slow.po power_slow.c
	@cc -shared -fpic -o libpowerslow.so power_slow.po
	@cc  main.o -L`pwd` -Wl,-R`pwd` -lpowerslow -o main
	./main 3

main2:
	@rm -fr *.o *.po *.so
	@cc -g -c -o main.o main.c
	@cc -g -DENABLE_DEF -fpic -c -o power_slow.po power_slow.c
	@cc -shared -fpic -o libpowerslow.so power_slow.po
	@cc  main.o -L`pwd` -Wl,-R`pwd` -lpowerslow -o main2
	./main2 3

main3:
	@rm -fr *.o *.po *.so
	@cc -g -DNO_USER_HOOK -c -o main.o main.c
	@cc -g -fpic -c -o power_slow.po power_slow.c
	@cc -shared -fpic -o libpowerslow.so power_slow.po
	@cc  main.o -L`pwd` -Wl,-R`pwd` -lpowerslow -o main3
	./main3 3

main4:
	@rm -fr *.o *.po *.so
	@cc -g -DNO_USER_HOOK -c -o main.o main.c
	@cc -g -DENABLE_DEF -fpic -c -o power_slow.po power_slow.c
	@cc -shared -fpic -o libpowerslow.so power_slow.po
	@cc  main.o -L`pwd` -Wl,-R`pwd` -lpowerslow -o main4
	./main4 3


clean:
	@rm -fr *.o *.po *.so main main2 main3 main4 
