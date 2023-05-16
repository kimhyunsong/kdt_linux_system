#include "../lib/syshdr.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>


int main(int argc, char *argv[])
{

    int flags, opt;
    // 메시지 큐
    mqd_t mqd;
    // 우선순위
    unsigned int prio;
    
    // 메시지 큐 속성
    struct mq_attr attr;
    // 읽을 버퍼와 사이즈
    ssize_t numRead;
    void *buffer;

    // 읽기전용
    flags = O_RDONLY;


    while ((opt = getopt(argc, argv, "n")) != -1) {
        switch (opt) {
            case 'n':
                flags |= O_NONBLOCK;
                break;
            default:
                exit(1);
        }
    }
    if (optind >= argc)
        exit(1);
    // 메시지 큐 생성
    mqd = mq_open(argv[optind], flags);
    if (mqd == (mqd_t) -1)
        exit(1);
    if (mq_getattr(mqd, &attr) == -1)
        exit(1);
    // 버퍼 동적 할당
    buffer = malloc(attr.mq_msgsize);
    if (buffer == NULL)
        exit(1);
    // 메시지 수신
    numRead = mq_receive(mqd, buffer, attr.mq_msgsize, &prio);
    if (numRead == -1)
        exit(1);
    printf("Read %ld bytes; priority = %u\n", (long) numRead, prio);

    // 버퍼에서 출력
    if (write(STDOUT_FILENO, buffer, numRead) == -1)
        exit(1);
    write(STDOUT_FILENO, "\n", 1);
    exit(EXIT_SUCCESS);
}
