#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mm.h>

MODULE_LICENSE("GPL");

#define body(prefix) \
  do { \
    char *buf; \
    buf = prefix##malloc(sizeof(int), GFP_KERNEL); \
    if (!buf) { \
      printk(KERN_ERR"kmalloc failed\n"); \
      return -ENOMEM; \
    } \
    buf[0] = 0x04; \
    buf[1] = 0x03; \
    buf[2] = 0x02; \
    buf[3] = 0x01; \
    printf("int: 0x%08X\n", *((int *) buf)); \
    prefix##free(buf); \
    return 0; \
  } while (0);

static int k() 
{
  body(k);
}

static int v()
{
  body(v);
}

int init_module(void)
{
  k();
  v();
  return 0;
}


void cleanup_module(void)
{
  printk("malloc_usage cleanup_module\n");
}

