#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

int get_no(void);

int init_module(void)
{
  int no;
  printk("export_sym_consumer init_module\n");
  no = get_no();
  printk("no: %d\n", no);
  return 0;
}

void cleanup_module(void)
{
  printk("export_sym_consumer cleanup_module\n");
}
