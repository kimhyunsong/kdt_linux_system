#include "../lib/syshdr.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>


int getInt(const char *arg, int flags, const char *name) {
    char *endptr;
    int res = strtol(arg, &endptr, flags);
    if (*endptr != '\0') {
        fprintf(stderr, "Invalid numeric argument for %s: %s\n", name, arg);
        exit(EXIT_FAILURE);
    }
    return res;
}
int main(int argc, char *argv[])
{
	int flags, opt;
	mode_t perms;
	//메시지 큐 선언
	mqd_t mqd;
	struct mq_attr attr, *attrp;
	// 메시지 큐 속성 설정
	attrp = NULL;
	// 메시지 개수
	attr.mq_maxmsg = 10;
	// 메시지 사이즈
	attr.mq_msgsize = 2048;
	// r/w 모두 허용
	flags = O_RDWR;
	// getopt : 명령행 인수를 처리하기 위한 함수
	// 인수의 배열과 각 인수의 문자열의 포인터를 받아 다음에 처리할 옵션 문자를 찾고
	// 해당 값을 저장, 더이상 처리할 옵션이 없는경우 -1 반환
	while ((opt = getopt(argc, argv, "cm:s:x")) != -1)
	{
		switch (opt){
			// 생성 권한 설정
			case 'c':
				flags |= O_CREAT;
				break;
			//메시지 개수를 인자로 받음
			case 'm':
				// optarg : getopt() 함수로 파싱한 명령행 옵션 인자 값의 포인터
				// 파싱 중에 발견한 값을 optarg(포인터)에 저장
				attr.mq_maxmsg = atoi(optarg);
				attrp = &attr;
				break;
			case 's':
				attr.mq_maxmsg = atoi(optarg);
				attrp = &attr;
				break;
			case 'x':
				flags |= O_EXCL;
				break;
			default:
				exit(1);
		}
	}
	// optind : getopt()함수에서 처리되지 않은 인자의 인덱스 
	if (optind >= argc)
		exit(1);
	// argv에서 마지막 인덱스에 있는 octal-perms값을 8진수로 변환하여 getInt함수로 호출
	perms = (argc <= optind + 1) ? (S_IRUSR | S_IWUSR) : getInt(argv[optind + 1], 0100, "octal-perms");
	//메시지 큐 생성 : 이름, 속성, 인자, 속성 인자의 포인터
	mqd = mq_open(argv[optind], flags, perms, attrp);

}

