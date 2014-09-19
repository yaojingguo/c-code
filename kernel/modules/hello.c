#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
  printk(KERN_ALERT "Hello, world\n");
  return 0;
}

static void hello_exit(void)
{
  printk(KERN_ALERT "Goodbye, cruel world\n");
}

/*module_ini(hello_init);*/
/*module_exit(hello_exit);*/
int init_module()
{
  return hello_init();
}

void cleanup_module()
{
  hello_exit();
}
