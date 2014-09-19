#CC = gcc
#INCLUDES = -I/usr/src/linux-headers-$(shell uname -r)/include
#INCLUDES += -I/usr/src/linux-headers-3.13.0-32-generic/arch/x86/include
#%: %.c
#  $(CC) $(INCLUDES) $< -o $@

obj-m += hello.o
obj-m += kfifo.o
obj-m += inttype-example.o
obj-m += idr_test.o
obj-m += tasklet.o
obj-m += workqueue_usage.o
obj-m += workqueue_events.o
obj-m += atomic.o
obj-m += spinlock_usage.o
obj-m += rwlock_usage.o
obj-m += semaphore_usage.o
obj-m += mutex_usage.o
obj-m += seqlock_usage.o
obj-m += preempt_usage.o
obj-m += timer.o
obj-m += busy_loop.o
obj-m += small_delay.o
obj-m += schedule_timeout.o

module:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
