SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall 
LDFLAGS = -L$(shell pwd) -Wl,-R.
LDLIBS = -larith

example: example.o  libarith.a
	$(CC) $(CFLAGS) $(LDFLAGS) $< $(LDLIBS) -o $@

example: example.o  libarith.a
	$(CC) $(CFLAGS) $(LDFLAGS) $< $(LDLIBS) -o $@

libarith.a: $(OBJ)
	$(AR) cr $@ $^

%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	@rm -fr *.o *.a example
