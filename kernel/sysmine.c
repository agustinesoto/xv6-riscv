#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "syscall.h"
#include "defs.h"

#include <stdint.h>

// Implement the sys_mprotect function
uint64 sys_mprotect(void){
    int addr;
    int len;
    argint(0, &addr);
    argint(1, &len);

    uintptr_t addr_ptr = (uintptr_t)addr;
    return mprotect((void*) addr_ptr, len);
}

// Implement the sys_munprotect function
uint64 sys_munprotect(void){
    int addr;
    int len;
    argint(0, &addr);
    argint(1, &len);

    uintptr_t addr_ptr = (uintptr_t)addr;
    return munprotect((void*) addr_ptr, len);
}