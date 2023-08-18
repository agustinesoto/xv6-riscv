#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
getppid(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}