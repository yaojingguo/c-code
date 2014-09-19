#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

int init_module(void)
{
  int i;
  printk("before delay\n");
  for (i = 0; i < 10; i++)
    mdelay(100);
  printk("after delay\n");
  return 0;
}


void cleanup_module(void)
{
  printk("small_delay cleanup_module\n");
}

