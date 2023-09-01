#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(void) {

int pidancestor = 2;
printf("Yo soy tu pidancestor - dijo el proceso %d\n", getancestor(1), pidancestor);
exit(0);
}