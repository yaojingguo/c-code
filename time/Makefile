PROG=clock_gettime clock_settime clock_getres localtime gettimeofday
all: $(PROG)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(PROG)
