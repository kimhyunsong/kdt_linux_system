#include "../lib/syshdr.h"
#include <signal.h>
#include <libgen.h>
#define CMD_SIZE 200


int main(int argc, char *argv[])
{
	char cmd[CMD_SIZE];
	pid_t cp;

	setbuf(stdout, NULL);

	printf("Parent PID=%ld\n", (long) getpid());

	switch(cp = fork())
	{
		case -1:
			exit(1);
		case 0:
			printf("Child (PID=%ld) exiting\n", (long) getpid());
			exit(EXIT_SUCCESS);
		default:
			sleep(3);
			// 버퍼에 system함수에 들어갈 문자열 생성
			snprintf(cmd, CMD_SIZE, "ps | grep %s", basename(argv[0]));
			system(cmd);

			//자식 프로세스에게 SIGKILL을 보냈으나 wait 이 없음
			// zombie process로남음
			if (kill(cp, SIGKILL) == -1)
				exit(1);
			sleep(3);
			printf("After sending SIGKILL to zombie (PID=%ld):\n", (long) cp);
			system(cmd);
			exit(EXIT_SUCCESS);
	}
}
