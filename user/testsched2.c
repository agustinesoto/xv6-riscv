#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

#define NFORK 5

int main() {
    int n, pid;
    for (n = 0; n < NFORK; n++) {
        pid = fork();
        if (pid < 0)
            break;
        if (pid == 0) {
            printf("Child %d started\n", getpid());
            for (volatile int i = 0; i < 10; i++) {  // Reduced outer loop iterations
                for (volatile int j = 0; j < 10000000; j++) {}  // Reduced inner loop iterations
                sleep(1);  // Reduced sleep time
            }
            printf("Child %d finished\n", getpid());
            exit(0);
        } else {
            printf("Parent created child %d\n", pid);
            if (n % 2 == 1) {
                set_priority(pid,80);
                printf("Set priority for child %d\n", pid);
            }
        }
    }
    for (; n > 0; n--) {
        int wpid = wait(0);
        if (wpid >= 0) {
            printf("Child %d exited\n", wpid);
        }
    }
    exit(0);
}
