#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

int init_module(void)
{
  printk("export_sym_provider init_module\n");
  return 0;
}

void cleanup_module(void)
{
  printk("export_sym_provider cleanup_module\n");
}

int get_no(void)
{
  return 9;
}
EXPORT_SYMBOL(get_no);

