#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");

DEFINE_SPINLOCK(my_lock);

int init_module(void)
{
  unsigned long flags = 0;

  spin_lock(&my_lock);
  printk("spin_lock\n");
  spin_unlock(&my_lock);
  printk("spin_unlock\n");

  spin_lock_irqsave(&my_lock, flags);
  printk("spin_lock_irqsave\n");
  spin_unlock_irqrestore(&my_lock, flags);
  printk("spin_unlock_irqrestore\n");

  spin_lock_irq(&my_lock);
  printk("spin_lock_irq\n");
  spin_unlock_irq(&my_lock);
  printk("spin_unlock_irq\n");

  return 0;
}

void cleanup_module(void)
{
  printk("cleanup_module\n");
}

