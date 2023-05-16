#include "../lib/syshdr.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>


// 생성한 메시지 큐 출력
int main(int argc, char *argv[])
{
    mqd_t mqd;
    struct mq_attr attr;
    if (argc != 2 || strcmp(argv[1], "--help") == 0)
        exit(1);
    mqd = mq_open(argv[1], O_RDONLY);
    if (mqd == (mqd_t) -1)
        exit(1);
    if (mq_getattr(mqd, &attr) == -1)
        exit(1);
    printf("Maximum # of messages on queue:   %ld\n", attr.mq_maxmsg);
    printf("Maximum message size:             %ld\n", attr.mq_msgsize);
    printf("# of messages currently on queue: %ld\n", attr.mq_curmsgs);
    exit(EXIT_SUCCESS);
}