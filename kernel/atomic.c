#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");

static void atomic_test(void)
{
	atomic_t v;
	atomic_t u = ATOMIC_INIT(0);

	atomic_set(&v, 4);
	atomic_add(2, &v);
	atomic_inc(&v);
	printk("u: %d, v: %d\n", atomic_read(&u), atomic_read(&v));
}

static void bit_op_test(void)
{
	unsigned long word = 0;

	set_bit(0, &word);
	set_bit(1, &word);
	printk("word 0: %lx\n", word);
	clear_bit(1, &word);
	change_bit(0, &word);

	if (test_and_set_bit(0, &word))
		printk("wrong\n");

	word = 7;
	printk("word 1: %lx\n", word);
}


int init_module(void)
{
  atomic_test();
  bit_op_test();
  return 0;
}

void cleanup_module(void)
{
}

