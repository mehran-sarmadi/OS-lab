#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <uapi/asm-generic/unistd.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("98106156-98105751");
MODULE_DESCRIPTION("OSLab-Exp8-Part1");
MODULE_VERSION("0.01");

unsigned long *syscall_table_addr = (unsigned long *)0xffffffffc14b5300;

static int __init init_print_syscalls(void) {
    printk(KERN_INFO "INIT: Print Syscalls\n");
    int i;
    for (i = 0; i < NR_syscalls; i++)
        printk(KERN_INFO "Syscall %03d: %lx\n", i, (unsigned long)(syscall_table_addr + i));
    return 0;
}

static void __exit exit_print_syscalls(void) {
    printk(KERN_INFO "Exit: Print Syscalls\n");
}

module_init(init_print_syscalls);
module_exit(exit_print_syscalls);