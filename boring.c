#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <asm/errno.h>


static int boring_open(struct inode *, struct file *);
static ssize_t boring_read(struct file *, char *, size_t, loff_t *);
static ssize_t boring_write(struct file *, const char *, size_t, loff_t *);
static int boring_release(struct inode *, struct file *);


static int major;

static struct file_operations fops =
{
    .open = boring_open,
    .read = boring_read,
    .write = boring_write,
    .release = boring_release,
};

/* Initialization and teardown hooks */

static int boring_init(void)
{
    major = register_chrdev(0, "boring", &fops);
    if (major < 0)
    {
        printk ("boring: Registering the character device failed with %d\n", major);
        return major;
    }

    printk(KERN_INFO "boring: Registered boring device as major=%d\n", major);
    return 0;
}

static void boring_exit(void)
{
    unregister_chrdev(major, "boring");
    printk(KERN_INFO "boring: You're boring. I'm unloading.\n");
}

/* Character device file operations */

static int boring_open(struct inode *inode, struct file *file)
{
    printk(KERN_ERR "boring: This operation is not supported.\n");
    return -EINVAL;
}

static ssize_t boring_read(struct file *fp, char *buffer, size_t length, loff_t *offset)
{
    printk(KERN_ERR "boring: This operation is not supported.\n");
    return -EINVAL;
}

static ssize_t boring_write(struct file *fp, const char *buffer, size_t length, loff_t *offset)
{
    printk(KERN_ERR "boring: This operation is not supported.\n");
    return -EINVAL;
}

static int boring_release(struct inode *inode, struct file *file)
{
    printk(KERN_ERR "boring: This operation is not supported.\n");
    return -EINVAL;
}


module_init(boring_init);
module_exit(boring_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Erik Hollembeak");
MODULE_DESCRIPTION("A boring example of writing a loadable Linux kernel module");
MODULE_VERSION("0.0.2");
