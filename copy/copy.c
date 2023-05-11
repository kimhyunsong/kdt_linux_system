#include "../lib/syshdr.h"
#include <sys/stat.h>
#include <fcntl.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char *argv[])
{
	// open할 파일의 fd, 복사할 파일의 fd, file 생성flag 선언
	int iFd, oFd, openFlags;
	// 생성할 파일의 권한설정
	//mode_t filePerms;
	// 읽을 데이터 사이즈선언
	ssize_t numRead;
	char buf[BUF_SIZE];

	if (argc != 3 || strcmp(argv[1], "--help") == 0){
		exit(1);
	}
	// 파일을 읽기 전용으로 열기
	iFd = open(argv[1], O_RDONLY);
	if (iFd == -1)
	{
		perror(argv[2]);
		exit(EXIT_FAILURE);
		}
	openFlags = O_CREAT | O_WRONLY | O_TRUNC;
	/*
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
				S_IROTH | S_IWOTH;
	*/
	// filePerms = 0666;
	oFd = open(argv[2], openFlags, 0666);
	if (oFd == -1)
	{
		perror(argv[2]);
		exit(EXIT_FAILURE);
	}
	// 버퍼 사이즈 만큼 읽으면서 write.	
	while ((numRead = read(iFd, buf, BUF_SIZE)) > 0)
	{
		if (write(oFd, buf, numRead) != numRead)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
	}
	if (numRead == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	if (close(iFd) == -1)
	{
		perror("close input");
		exit(EXIT_FAILURE);
	}
	if (close(oFd) == -1)
	{
		perror("close output");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);

	return 0;
}
