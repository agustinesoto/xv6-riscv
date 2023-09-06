#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"
#include "kernel/syscall.h" 


/* Esta llamada debe retornar el id del proceso
padre del que llame a la función*/
uint64
sys_getppid(void)
{
  return myproc()->parent->pid;
}

uint64 sys_getancestor(void) {
    struct proc* p = myproc();
    int n;
    argint(0, &n);

    // Verify that 'n' is valid
    if (n < 0) {
        //printf("Número inválido!!\n");
        return -1; // Invalid number
    }

    // Navigate up the process hierarchy
    while (n > 0 && p != 0) {
        //printf("Recorriendo jerarquía, voy en %d\n", n);
        p = p->parent;
        n--;
    }

    if (n == 0 && p != 0) {
        //printf("Terminé y llegué al n-ésimo ancestro!!\n");
        return p->pid; // Desired process found
    } else {
        //printf("Terminé y no hay suficientes ancestros!!\n");
        return -1; // Not enough ancestors
    }
}



uint64 
sys_addone(void)
{
    int num;
    argint(0,&num); //retrieving first argument
    printf("%d - Inside system call!\n",num);
    return num + 1;
}

