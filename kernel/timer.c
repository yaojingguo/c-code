#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/semaphore.h>

MODULE_LICENSE("GPL");

void my_function(unsigned long data)
{
  printk("data: %ld\n", data);
}

struct timer_list my_timer;

int init_module(void)
{
  int delay;
  
  // CONFIG_HZ is 250 for my ubuntu box.
  delay = 3 * 250; // 3 seconds
  init_timer(&my_timer);
  my_timer.expires = jiffies + delay;
  my_timer.data = 100;
  my_timer.function = my_function;
  add_timer(&my_timer);
  printk("timer added\n");

  return 0;
}

void cleanup_module(void)
{
  printk("timer cleanup_module\n");
}

