Learning [Strong and Weak Symbols in
GCC](https://leondong1993.github.io/2017/04/strong-weak-symbol/).


```
$ cd /lib/x86_64-linux-gnu
$ nm -D libpthread.so.0 | ag pthread_create
00000000000079b0 T pthread_create
$ nm -D libc-2.27.so | grep recvfrom
0000000000122950 W recvfrom
```

The code in `Function of s. w. symbols` does not work as expected.
