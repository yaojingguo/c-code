all:
	cc -g -c -o main.o main.c
	cc -g -c -o power_slow.o power_slow.c
	cc -g -c -o power.o power.c
	cc  main.o power_slow.o         -o slow
	cc  main.o power_slow.o power.o -o fast

clean:
	@rm -fr *.o
	@rm -fr fast slow
