#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int allow_live_bait = 9;
module_param(allow_live_bait, int, 0644);

static int hello_init(void)
{
  printk(KERN_ALERT "I bear a charmed life.\n");
  return 0;
}

static void hello_exit(void)
{
  printk(KERN_ALERT "Out, out, brief candle\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Shakespeare");
MODULE_DESCRIPTION("A Hello, World Module");
