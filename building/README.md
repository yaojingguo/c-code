# TODO
- The order of -l and -L. Check -lpthread. 
- Test on Linux.
- Check the references of shared libraries in add_main and arith_main.
- Read the part of Scott 4e_Supplementary Sections about dynamic linking.



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
