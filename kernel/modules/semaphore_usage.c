#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/semaphore.h>

MODULE_LICENSE("GPL");


int init_module(void)
{
  struct semaphore sem;
  sema_init(&sem, 3);

  printk("3 downs\n");

  down_interruptible(&sem);
  printk("down 0\n");
  down_interruptible(&sem);
  printk("down 1\n");
  down_interruptible(&sem);
  printk("down 2\n");
  up(&sem);
  printk("up 0\n");
  up(&sem);
  printk("up 1\n");
  up(&sem);
  printk("up 2\n");

  printk("3 ups\n");

  return 0;
}

void cleanup_module(void)
{
  printk("cleanup_module\n");
}

