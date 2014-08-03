#include <linux/init.h>
#include <linux/kfifo.h>
#include <linux/module.h>

// This piece of code taints the kernel.

MODULE_LICENSE("Dual BSD/GPL");
struct kfifo fifo;

int init_module()
{
  int ret, i;
  if ((ret = kfifo_alloc(&fifo, PAGE_SIZE, GFP_KERNEL)) != 0)
    return ret;
  for (i = 0; i < 32; i++)
    kfifo_in(&fifo, &i, sizeof(i));
  return 0;
}

void cleanup_module()
{
  int ret;
  int val;
  while (kfifo_avail(&fifo)) {
    ret = kfifo_out(&fifo, &val, sizeof(val));
    if (ret != sizeof(val))
      printk(KERN_INFO "kfifo_out error: %d\n", ret);
    printk(KERN_INFO "%d\n", val);
  }
  kfifo_free(&fifo);
}
