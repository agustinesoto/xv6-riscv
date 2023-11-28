#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#include "kernel/riscv.h"

int main(int argc, char *argv[]) {
  
  // Allocate a page of memory using sbrk
  char *start = sbrk(0);
  sbrk(PGSIZE);
  
  // Set a value in the allocated memory
  *start = 100;
  
  // Protect the allocated memory page
  mprotect(start, 1);
  
  // Create a child process
  int child = fork();
  
  if (child == 0) {
    // Child process
    printf("protected value = %d\n", *start);
    
    // Unprotect the memory, allowing modification
    munprotect(start, 1);
    
    // Modify the value after unprotecting
    *start = 5;
    printf("After unprotecting the value became = %d\n", *start);
    
    // Exit the child process
    exit(0);
  } else if (child > 0) {
    // Parent process
    wait(0);
    printf("\nWatch this, I'll trap now\n");
    
    // Attempt to modify the protected memory (should trigger an error)
    *start = 5;
    
    // This statement will not be printed because of the protection
    printf("\nThis statement will not be printed\n");
    
    // Exit the parent process
    exit(0);
  }
  
  // The following code is commented out and not executed in the current version
  /*
  char arr[] = {'1', '2', '3', '4'};
  arr[0] = 'a';
  printf(1, "\narr[0] = %d\n", arr[0]);
  mprotect((void *)(((uint)arr / PGSIZE) * PGSIZE), 1);
  printf(1, "reached here \n");
  // munprotect((void *)(((uint)arr/PGSIZE-1)*PGSIZE),1);
  arr[0] = 'b';
  printf(1, "\narr[0] = %d\n", arr[0]);
  */
  
  return 0;
}
