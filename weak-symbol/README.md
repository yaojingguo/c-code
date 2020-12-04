https://en.wikipedia.org/wiki/Weak_symbol

`make check`:
```
make check
nm power_slow.o | grep power
0000000000000000 W power2
0000000000000034 T power3

nm power.o | grep power
0000000000000000 T power2

nm main.o | grep power
                 U power3

nm slow | grep power
0000000000000767 W power2
000000000000079b T power3

nm fast | grep power
00000000000007b6 T power2
000000000000079b T power3
```
