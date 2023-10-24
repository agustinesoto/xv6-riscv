#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "syscall.h"
#include "defs.h"


uint64
sys_set_priority(void)
{
  int proc_id;
  int priority;
  argint(0, &proc_id);
  argint(1, &priority);
  return set_priority(proc_id, priority);
}