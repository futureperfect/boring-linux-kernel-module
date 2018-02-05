#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int boring_init(void)
{
    printk(KERN_INFO "Blah blah blah, etcetera etcetera.\n");
    return 0;
}

static void boring_exit(void)
{
    printk(KERN_INFO "You're boring. I'm unloading.\n");
}

module_init(boring_init);
module_exit(boring_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Erik Hollembeak");
MODULE_DESCRIPTION("A boring example of writing a loadable Linux kernel module");
MODULE_VERSION("0.0.1");
