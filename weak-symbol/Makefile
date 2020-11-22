all:
	cc -g -c -o main.o main.c
	cc -g -c -o power_slow.o power_slow.c
	cc -g -c -o power.o power.c
	cc  main.o power_slow.o         -o slow
	cc  main.o power_slow.o power.o -o fast

check:
	nm power_slow.o | grep power
	@echo
	nm power.o | grep power
	@echo
	nm main.o | grep power
	@echo
	nm slow | grep power
	@echo
	nm fast | grep power

clean:
	@rm -fr *.o
	@rm -fr fast slow
