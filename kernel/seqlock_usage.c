#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");

DEFINE_SEQLOCK(slock);

int init_module(void)
{
  unsigned long seq;

  write_seqlock(&slock);
  printk("write_seqlock\n");
  write_sequnlock(&slock);
  printk("write_sequnlock\n");

  seq = read_seqbegin(&slock);
  printk("read_seqbegin\n");
  if (read_seqretry(&slock, seq))
    printk("wrong\n");

  return 0;
}


void cleanup_module(void)
{
  printk("cleanup_module\n");
}

