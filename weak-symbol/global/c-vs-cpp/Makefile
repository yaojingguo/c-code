_c:
	$(CC) -c -o c/main.o c/main.c
	$(CC) -c -o c/aux.o c/aux.c
	$(CC) -o c/test c/main.o c/aux.o

_cpp:
	$(CC) -c -o cpp/main.o cpp/main.cpp
	$(CC) -c -o cpp/aux.o cpp/aux.cpp
	$(CC) -o cpp/test cpp/main.o cpp/aux.o

clean:
	@rm -fr c/*.o cpp/*.o
	@rm -fr c/test cpp/test

