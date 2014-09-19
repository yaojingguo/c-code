#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/semaphore.h>

MODULE_LICENSE("GPL");

int init_module(void)
{
  preempt_disable();
  printk("preempt_disable 0\n");
  printk("preempt_count: %d\n", preempt_count());
  preempt_disable();
  printk("preempt_disable 1\n");
  printk("preempt_count: %d\n", preempt_count());

  preempt_enable();
  printk("preempt_enable 0\n");
  printk("preempt_count: %d\n", preempt_count());
  preempt_enable();
  printk("preempt_enable 1\n");
  printk("preempt_count: %d\n", preempt_count());

  return 0;
}

void cleanup_module(void)
{
  printk("cleanup_module\n");
}

