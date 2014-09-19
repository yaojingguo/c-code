#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

int init_module(void)
{
  unsigned long timeout = jiffies + 250 * 10; // 10s
  printk("begin to wait\n");
  while (time_before(jiffies, timeout))
    ;
  printk("expire\n");
  return 0;
}

void cleanup_module(void)
{
  printk("busy_loop cleanup_module\n");
}

