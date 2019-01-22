PROG=clock_gettime clock_settime clock_getres localtime gettimeofday strftime strptime
all: $(PROG)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(PROG)
