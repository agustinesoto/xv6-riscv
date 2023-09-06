#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(void) {

//int pidancestor = 1;

printf("Yo soy yo - dijo el proceso %d\n", getpid());
printf("----\n");
printf("Yo soy tu pidancestor - dijo el proceso %d\n", getancestor(0));
printf("----\n");
printf("Yo soy tu padre - dijo el proceso %d\n", getppid());
printf("----\n");
printf("Yo soy tu pidancestor - dijo el proceso %d\n", getancestor(1));
printf("----\n");
printf("Yo soy tu pidancestor - dijo el proceso %d\n", getancestor(2));
printf("----\n");
printf("Yo soy tu pidancestor - dijo el proceso %d\n", getancestor(3));
printf("----\n");
printf("Yo soy tu pidancestor - dijo el proceso %d\n", getancestor(4));
printf("----\n");
printf("Yo soy tu pidancestor -11 - dijo el proceso %d\n", getancestor(-1));
printf("----\n");
exit(0);
}