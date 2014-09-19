#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");

DEFINE_RWLOCK(rwlock);

int init_module(void)
{
  printk("rwlock_usage module\n");

  read_lock(&rwlock);
  printk("read_lock 0\n");
  read_lock(&rwlock);
  printk("read_lock 1\n");

  read_unlock(&rwlock);
  printk("read_unlock 0\n");
  read_unlock(&rwlock);
  printk("read_unlock 1\n");

  write_lock(&rwlock);
  printk("write_lock\n");
  write_unlock(&rwlock);
  printk("write_unlock\n");

  return 0;
}

void cleanup_module(void)
{
  printk("cleanup_module\n");
}

