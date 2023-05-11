#include "../lib/syshdr.h"
#define _BSD_SOURCE
// 메모리 및 debugging 용
char globBuf[65536];
int prime[] = {2, 3, 5, 7};

static int
square(int x)
{
	int result;
	result = x * x;
	return result;
}

static void doCalc(int val)
{
	printf("The square of %d is %d\n", val, square(val));

	if (val < 1000)
	{
		int t;
		t = val * val * val;
		printf("The cub of %d is %d\n", val, t);
	}
}

int main(int argc, char *argv[])
{
	static int key = 9973;
	static char mbuf[10240000];
	char *p;
	p = malloc(1024);
	doCalc(key);

	exit(EXIT_SUCCESS);
}

