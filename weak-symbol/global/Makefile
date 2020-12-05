FUNC_NAME = pthread_create

all: func.c
	$(CC) -o single $<
	$(CC) -o multiple $< -pthread	
	nm single | grep $(FUNC_NAME)
	nm multiple | grep $(FUNC_NAME)
	nm -D /lib/x86_64-linux-gnu/libpthread.so.0 | grep $(FUNC_NAME)

clean:
	@rm -fr *.o single multiple
