#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");

char my_tasklet_data[] = "my_tasklet_function was called";

void my_tasklet_function(unsigned long data)
{
  printk(KERN_INFO "%s\n", (char *)data);
}

DECLARE_TASKLET(my_tasklet, my_tasklet_function, (unsigned long) &my_tasklet_data);

int init_module(void)
{
  tasklet_schedule(&my_tasklet);
  return 0;
}

void cleanup_module(void)
{
  tasklet_kill(&my_tasklet);
}

