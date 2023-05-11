#include "../lib/syshdr.h"
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	// childprocess
	int cp;
	pid_t childPid;

	if (argc > 1 && strcmp(argv[1], "--help") == 0)
	{
		exit(1);
	}
	cp = (argc > 1) ? atoi(argv[1]) : 1;
	// 출력 버퍼를 0으로 설정
	setbuf(stdout, NULL);
	for (int i =0; i < cp; i++){
		switch(childPid = fork()) 
		{
			case -1:
				perror("fork error");
				exit(1);
			// 자식 프로세스에서 수행
			case 0:
				printf("%d번째 child: %d\n",i+ 1, getpid());
				break;
			default:
				printf("부모: %d\n",getpid());
				// 부모가 자식 프로세스의 종료를 기다림
				wait(NULL);
				break;
		}
	}
	exit(EXIT_SUCCESS);


}

