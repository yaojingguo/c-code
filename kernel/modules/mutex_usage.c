#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/mutex.h>

MODULE_LICENSE("GPL");

int init_module(void)
{
  struct mutex lock;
  mutex_init(&lock);

  mutex_lock(&lock);
  printk("mutex_lock\n");
  mutex_unlock(&lock);
  printk("mutex_unlock\n");
  
  return 0;
}

void cleanup_module(void)
{
  printk("cleanup_module\n");
}

