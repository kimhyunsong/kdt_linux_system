#include "../lib/syshdr.h"
#include <signal.h>

static void sigHandler(int sig)
{
	printf("Ouch!\n");
}

int main(int argc, char *argv[])
{
	// SIGINT == Ctrl+C // 해당 값을 받으면 sigHandler 호출
	// return 값은 이전에 등록된 시그널 핸들러 함수의 주소
	// 등록된 핸들러가 없을 경우 SIG_ERR(-1) 반환
	if (signal(SIGINT, sigHandler) == SIG_ERR){
		perror("signal error");
		exit(1);
	}

	for (int i = 0; ; i++){
		printf("%d\n", i);
		sleep(1);
	
	}
	return 0;
}

		
