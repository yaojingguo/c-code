Learning [Strong and Weak Symbols in
GCC](https://leondong1993.github.io/2017/04/strong-weak-symbol/).


```
$ cd /lib/x86_64-linux-gnu
$ nm -D libpthread.so.0 | grep pthread_create
00000000000079b0 T pthread_create
$ nm -D libc-2.27.so | grep recvfrom
0000000000122950 W recvfrom
```

The code in `Function of s. w. symbols` does not work as expected. Since a `w`
symbol in a object file takes precedence over a `T` symbol in a shared library.

```
$ nm c/main.o | grep gvar
0000000000000004 C gvar
$ nm c/aux.o | grep gvar
0000000000000000 D gvar
$ nm c/test | grep gvar
0000000000201010 D gvar

$ nm cpp/main.o | grep gvar
0000000000000000 B gvar
$ nm cpp/aux.o | grep gvar
0000000000000000 D gvar
$ cc -o cpp/test cpp/main.o cpp/aux.o
cpp/aux.o:(.data+0x0): multiple definition of `gvar'
cpp/main.o:(.bss+0x0): first defined here
collect2: error: ld returned 1 exit status
Makefile:7: recipe for target '_cpp' failed
make: *** [_cpp] Error 1
```
