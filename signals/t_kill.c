#include "../lib/syshdr.h"
#include <signal.h>

int main(int argc, char *argv[])
{
	int s, sig;
	if (argc != 3 || strcmp(argv[1], "--help") == 0){
		perror("usageErr");
		exit(1);
	}
	
	sig = atoi(argv[2]);
	// 시그널을 받을 PID , 시그널 종류
	s = kill(atoi(argv[1]), sig);
	if (sig!=0){
		//kill 실패할 경우
		if (s == -1)
			exit(1);
	} else {
		// 시그널이 성공적으로 전달된경우
		if (s == 0) {
			printf("can send it a signal\n");
		} else {
			 if (errno == EPERM)
			 	printf("Process exists, but we don't have "
                        "permission to send it a signal\n");
             else if (errno == ESRCH)
                 printf("Process does not exist\n");
             else
                 exit(1);

		}
	}
		
			


}
