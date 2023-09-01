#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"
#include "kernel/syscall.h" // You may need this if your syscall numbers are defined here.
/* Esta llamada debe retornar el id del proceso
padre del que llame a la función*/
uint64
sys_getppid(void)
{
  return myproc()->parent->pid;
}

uint64 sys_getancestor(void) {
return -1;
}

uint64 
sys_addone(void)
{
    int num;
    argint(0,&num); //retrieving first argument
    printf("%d - Inside system call!",num);
    return num + 1;
}

