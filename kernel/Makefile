#CC = gcc
#INCLUDES = -I/usr/src/linux-headers-$(shell uname -r)/include
#INCLUDES += -I/usr/src/linux-headers-3.13.0-32-generic/arch/x86/include
#%: %.c
#  $(CC) $(INCLUDES) $< -o $@

obj-m += hello.o
hello:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
 
