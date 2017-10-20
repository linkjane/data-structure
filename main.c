#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "link-queue.h"

int main() {

    LinkQueue *linkQueue;
    linkQueueInit(&linkQueue);
    linkQueuePush(linkQueue, 10);
    linkQueuePush(linkQueue, 20);
    linkQueuePush(linkQueue, 25);
    linkQueuePush(linkQueue, 30);
    linkQueueET res;
    linkQueuePop(linkQueue, &res);
    printf("弹出的header值是:%d\n", res);
    linkQueuePop(linkQueue, &res);
    printf("弹出的header值是:%d\n", res);
    linkQueuePop(linkQueue, &res);
    printf("弹出的header值是:%d\n", res);
    linkQueuePop(linkQueue, &res);
    printf("弹出的header值是:%d\n", res);
    linkQueuePop(linkQueue, &res);
    printf("弹出的header值是:%d\n", res);

    printf("开始遍历\n");
    linkQueueTraverse(*linkQueue);
    printf("队列长度是:%d\n", linkQueue->length);
}


