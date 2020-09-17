# TODO
- The order of -l and -L. Check -lpthread. 
- Test on Linux.
- Check the references of shared libraries in add_main and arith_main.
- Read the part of Scott 4e_Supplementary Sections about dynamic linking.


Dependency diagram:
```
add.c   -----> libadd.so   -----> add_main
                                     ^ 
                                     |
               add_main.c  ----------+

               libadd.so   ----------+
                                     |
                                     v
arith.c -----> libarith.so ------> arith_main
                              |
                              +--> bad_arith_main
```

```
$ ./bad_arith_main
dyld: lazy symbol binding failed: Symbol not found: _add
  Referenced from: libarith.so
  Expected in: flat namespace

dyld: Symbol not found: _add
  Referenced from: libarith.so
  Expected in: flat namespace

[1]    24469 abort      ./bad_arith_main
```

Symbol checking:
```bash
// Care about add which is a direct reference
$ nm -g -u libarith.so
_add
dyld_stub_binder
// Does not care about add which is a indirect reference here
$ nm -g -u arith_main
_printf
_subtract
_sum
dyld_stub_binder
```

```
$ make libxxx.so
cc -shared -o libxxx.so arith.o
Undefined symbols for architecture x86_64:
  "_add", referenced from:
      _sum in arith.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make: *** [libxxx.so] Error 1
```
