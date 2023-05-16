#include "../lib/syshdr.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>


// 메시지 큐 전송
int main(int argc, char *argv[])
{
    int flags, opt;
    // 메시지 큐
    mqd_t mqd;
    // 우선순위
    unsigned int prio;
    // 쓰기전용
    flags = O_WRONLY;
    while ((opt = getopt(argc, argv, "n")) != -1)
    {
        switch(opt) {
            // 오버헤드 방지(?)
            case 'n': flags |= O_NONBLOCK;
            default: exit(1);
        }
    }

    if (optind + 1 >= argc)
        exit(1);
    // 메시지 큐 생성
    mqd = mq_open(argv[optind], flags);
    // 우선순위를 설정한 경우 해당값, 아닐 경우 0
    prio = (argc > optind + 2) ? atoi(argv[optind + 2]) : 0;
    // 메시지 전송
    // 메시지큐, 메시지 포인터, 메시지 길이, 우선순위
    if (mq_send(mqd, argv[optind + 1], strlen(argv[optind + 1]), prio) == -1)
        exit(1);
    exit(0);

}