CC = gcc
INCLUDES = -I/usr/src/linux-headers-$(shell uname -r)/include
%: %.c
	$(CC) $(INCLUDES) $< -o $@
