#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_getppid(void)
{
 return 1;
}
// todas las llamadas a sistema DEBEN retornar 1
