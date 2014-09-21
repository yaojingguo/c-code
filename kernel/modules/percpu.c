#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static void one(void)
{
  int cpu;
  unsigned int my_percpu[NR_CPUS];

  printk("cpu count: %d\n", NR_CPUS);
  cpu = get_cpu();
  my_percpu[cpu]++;
  printk("my_percpu on cpu=%d is %u\n", cpu, my_percpu[cpu]);
  put_cpu();
}

static int two(void)
{
  void *percpu_ptr;
  unsigned *foo;

  percpu_ptr = alloc_percpu(unsigned);
  if (!percpu_ptr) {
    printk("alloc_percpu failed\n");
    return -ENOMEM;
  }
  foo = get_cpu_var(percpu_ptr);
  *foo = 10;
  printk("foo: %u\n", *foo);
  return 0;
}

int init_module(void)
{
  int ret;

  printk("percpu init_module\n");
  one();
  if (!(ret = two()))
    return ret;
  return 0;
}


void cleanup_module(void)
{
  printk("slab_usage cleanup_module\n");
}

