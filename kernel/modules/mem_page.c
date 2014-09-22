#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mm.h>

MODULE_LICENSE("GPL");

int init_module(void)
{
  struct page *page;
  void *addr;
  long *p;
  int i;

  page = alloc_pages(GFP_KERNEL, 0);
  if (!page) {
    printk(KERN_ERR"__get_free_pages failed\n");
    return -ENOMEM;
  }
  addr = page_address(page);
  p = (long*) addr;
  *p = 0x0001020304050607;

  for (i = 0; i < 8; i++)
    printk("byte %d: 0x%2X\n", i,((char*) addr)[i]);

  __free_pages(page, 0);

  return 0;
}

void cleanup_module(void)
{
  printk("mem_page cleanup_module\n");
}

