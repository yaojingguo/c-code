#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/workqueue.h>

MODULE_LICENSE("GPL");

static struct workqueue_struct *my_wq;

typedef struct {
	struct work_struct my_work;
	int x;
} my_work_t;

static void my_wq_function(struct work_struct *w)
{
	my_work_t *my_work = (my_work_t*) w;
	printk(KERN_INFO "my_work.x %d\n", my_work->x);
	kfree((void*) w);
}

my_work_t *work, *work2;

int init_module(void)
{
	int ret;

	my_wq = create_workqueue("my_work");
	if (my_wq) {
		work = (my_work_t *) kmalloc(sizeof(my_work_t), GFP_KERNEL);
		if (work) {
			INIT_WORK((struct work_struct *) work, my_wq_function);
			work->x = 1;
			ret = queue_work(my_wq, (struct work_struct *) work);
      /*
      if (!ret) 
        printk(KERN_ERR "queue_work work failed\n");
      */
		} else {
      printk(KERN_ERR "create work failed\n");
    }
        

		work2 = (my_work_t *) kmalloc(sizeof(my_work_t), GFP_KERNEL);
		if (work2) {
			INIT_WORK((struct work_struct *) work2, my_wq_function);
			work2->x = 2;
			ret = queue_work(my_wq, (struct work_struct *) work2);
      /*
      if (!ret)
        printk(KERN_ERR "queue_work work2 failed\n");
      */
		} else {
      printk(KERN_ERR "create work2 failed\n");
    }
	} else {
    printk(KERN_ERR "create_workqueue failed\n");
  }
	return 0;
}

void cleanup_module(void)
{
	flush_workqueue(my_wq);
	destroy_workqueue(my_wq);
	return;
}
