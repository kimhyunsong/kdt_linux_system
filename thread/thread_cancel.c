#include "../lib/syshdr.h"
#include <pthread.h>

static void * threadFunc(void *arg)
{
	printf("New Thread started\n");
	// 종료 되기 전까지 계속 돎
	for (int i =1; ;i++){
		printf("Loop %d\n", i);
		sleep(1);
	}
}

int main(int argc, char *argv[])
{
	pthread_t thr;
	int s;
	void *res;
	// 스레드 생성
	s = pthread_create(&thr, NULL, threadFunc, NULL);
	if (s!= 0)
		exit(1);
	// 스레드 생성 후 3초 간 재움	
	sleep(3);
	// 스레드 취소
	s = pthread_cancel(thr);
	if (s != 0)
		exit(1);
	// 취소한 스레드 종료 대기
	s = pthread_join(thr, &res);
	if (s != 0)
		exit(1);
	
}
