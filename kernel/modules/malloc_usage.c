#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");


#define body(prefix) \
  do { \
    char *buf; \
    MALLOC; \
    if (!buf) { \
      printk(KERN_ERR"kmalloc failed\n"); \
      return -ENOMEM; \
    } \
    buf[0] = 0x04; \
    buf[1] = 0x03; \
    buf[2] = 0x02; \
    buf[3] = 0x01; \
    printk("int: 0x%08X\n", *((int *) buf)); \
    prefix##free(buf); \
    return 0; \
  } while (0)

static int k(void) 
{
#ifdef MALLOC
#undef MALLOC
#endif
#define MALLOC do { buf = kmalloc(sizeof(int), GFP_KERNEL); } while (0)
  body(k);
  return 0;
}

static int v(void)
{
#ifdef MALLOC
#undef MALLOC
#endif
#define MALLOC do { buf = vmalloc(sizeof(int)); } while (0)
  body(v);
  return 0;
}

int init_module(void)
{
  printk("malloc_usage init_module\n");
  k();
  v();
  return 0;
}


void cleanup_module(void)
{
  printk("malloc_usage cleanup_module\n");
}

