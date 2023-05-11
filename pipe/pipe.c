#include "../lib/syshdr.h"
#define BUF_SIZE 10

int main(int argc, char*argv[])
{
	// 파이프 시스템콜에서 생성하는 fd
	int pfd[2];
	char buf[BUF_SIZE];
	ssize_t numRead;

	if (argc != 2 || strcmp(argv[1], "--help") == 0)
		exit(1);
	if (pipe(pfd)){
		perror("pipe error");
		exit(1);
	}

	// 자식 프로세스 생성
	switch(fork())
	{
		case -1:
			perror("fork error");
			exit(1);
		// 자식 프로세스 수행
		case 0:
			while(1)
			{
				numRead = read(pfd[0], buf, BUF_SIZE);
				if (numRead == -1)
					exit(1);
				// EoF
				if (numRead == 0)
					break;
				//STDOUT_FILENO == 1 == 표준 출력
				if (write(STDOUT_FILENO, buf, numRead) != numRead)
					exit(1);
			}
			//읽은 문자를 한줄씩 출력 
			write(STDOUT_FILENO, "\n", 1);
			// 메모리반환
			if (close(pfd[0] == -1))
				exit(1);
			exit(EXIT_SUCCESS);
		// 부모 프로세스 수행
		default:
			if (close(pfd[0]) == -1)
				exit(1);
			// 인자로 넘겨준 값을작성 
			if (write(pfd[1], argv[1], strlen(argv[1])) != strlen(argv[1]))
				exit(1);
			// 자식 프로세스 대기
			wait(NULL);
			exit(EXIT_SUCCESS);
			
	}
}
