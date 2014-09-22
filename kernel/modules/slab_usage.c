#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

struct person_struct {
  int no;
  int age;
};

int init_module(void)
{
  struct kmem_cache *cachep;
  struct person_struct *yao;

  printk("slab_usage init_module\n");

  cachep = kmem_cache_create("person_struct",
                              sizeof(struct person_struct),
                              0,
                              0,
                              NULL);
  yao = kmem_cache_alloc(cachep, GFP_KERNEL);
  if (!yao)
    return -ENOMEM;
  yao->no = 0;
  yao->age = 38;
  printk("{no: %d, age: %d}\n", yao->no, yao->age);
  kmem_cache_free(cachep, yao);
  
  return 0;
}

void cleanup_module(void)
{
  printk("slab_usage cleanup_module\n");
}

