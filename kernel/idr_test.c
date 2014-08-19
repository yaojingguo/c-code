#include <linux/init.h>
#include <linux/module.h>
#include <linux/idr.h>

struct person {
  int no;
};

static int __init example_init(void)
{
  struct idr id_huh;
  struct person yao = { .no = 10, };
  struct person *result;
  int id;

  printk(KERN_INFO "example_init\n");
  idr_preload(GFP_KERNEL);
  id = idr_alloc(&id_huh, &yao, 1, 0, GFP_KERNEL);
  idr_preload_end();
  printk(KERN_INFO "idr_alloc\n");

  if (id < 0) {
    printk(KERN_INFO "id < 0\n");
    return id;
  }

  result = idr_find(&id_huh, id);
  printk(KERN_INFO "idr_find\n");
  if (result != NULL) 
    printk(KERN_INFO "no: %d\n", result->no);
  else 
    printk("find null\n");

  idr_remove(&id_huh, id);
  printk(KERN_INFO "idr_remove\n");
  idr_destroy(&id_huh);
  printk(KERN_INFO "idr_destroy\n");
  return 0;
}

static void __exit example_exit(void)
{
  printk(KERN_INFO "idr_exit\n");
}

module_init(example_init);
module_exit(example_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jingguo Yao <yaojingguo@gmail.com>");
