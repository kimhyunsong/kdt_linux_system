#include "../lib/syshdr.h"
#include <stdlib.h>
int main(int argc, char *argvp[])
{
	printf("USER : %s\n", getenv("USER"));
	printf("pid : %d\n", getpid());
	if (putenv("USER=testSsong") != 0)
		exit(1);
	// printenv 명령어 실행 ("printenv", "USER", "SHELL", (char *) NULL);
	execl("/usr/bin/printenv", "printenv", "USER", "SHELL", (char *) NULL);
	//아래부터는 실행되지 않는다.
	exit(1);
}
