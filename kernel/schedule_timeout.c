#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

int init_module(void)
{
  printk("HZ: %d\n", HZ);
  printk("before schedule_timeout\n");
  set_current_state(TASK_INTERRUPTIBLE);
  schedule_timeout(5 * 4 * HZ);
  printk("after schedule_timeout\n");

  return 0;
}


void cleanup_module(void)
{
  printk("schedule_timeout cleanup_module\n");
}

