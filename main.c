#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "sequence-queue.h"


int main() {
    Queue *queue;

    queueInit(&queue);
    queuePush(queue, 233);
    queuePush(queue, 10);
    queuePush(queue, 140);
    queueET res;
    queuePop(queue,&res);
    queuePop(queue,&res);
    printf("队列的弹出的header的值是%d\n", res);
    queueFront(*queue, &res);
    printf("队列的返回的header的值是%d\n", res);
    queueBack(*queue, &res);
    printf("队列的返回的rear的值是%d\n", res);

    printf("开始遍历队列\n");
    queueTraverse(*queue);
    printf("队列的长度是%d\n", queueLength(*queue));
    printf("队列的最大长度是%d\n", queue->maxSize);

}



