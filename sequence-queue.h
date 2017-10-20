
#include <mach_debug/ipc_info.h>

typedef int queueET;

typedef struct {
    queueET *base;
    queueET *rear;
    queueET *header;
    int maxSize;
} Queue ;


status queueInit(Queue **queue) {
    //在这分配内存外部为什么也会有
    *queue = malloc(sizeof(Queue));
    if (!*queue) {
        printf("分配队列失败\n");
        return ERROR;
    }
    //初始化只给二个空间, 对半增加
    (*queue)->base = malloc(sizeof(queueET));
    if (!(*queue)->base) {
        printf("分配队列内部存储值失败\n");
        return ERROR;
    }

    (*queue)->rear = (*queue)->header = (*queue)->base;
    (*queue)->maxSize = 1;
    return SUCCESS;
}

status queuePush(Queue *queue, queueET val) {

    if (queue->header - queue->rear >= queue->maxSize) {
        queue->maxSize *= 2;
        queue->base = realloc(queue->base, sizeof(queue->maxSize)) ;
        if (!queue->base) {
            printf("队列内部分配内存失败\n");
            return ERROR;
        }
    }

    queueET *cursor = queue->header;
    while (cursor != queue->rear) {
        *cursor = *(cursor - 1);
        cursor--;
    }

    *(queue->rear) = val;
    queue->header++;
    return SUCCESS;
}

int queueLength(Queue queue) {
    return queue.header - queue.rear;
}


status queuePop(Queue *queue, queueET *res) {
    if (queue->header == queue->rear && queue->rear != NULL) {
        printf("队列为空\n");
        *res = 0;
        return ERROR;
    }
    *res = *(--queue->header);
    *queue->header = NULL;
    return SUCCESS;
}

status queueFront(Queue queue, queueET *res) {
    if (queue.header == queue.rear) {
        printf("队列为空\n");
        *res = 0;
        return ERROR;
    }
    *res = *(queue.header - 1);
}

status queueBack(Queue queue, queueET *res) {
    if (queue.header == queue.rear) {
        printf("队列为空\n");
        *res = 0;
        return ERROR;
    }

    *res = *queue.rear;
}


status queueTraverse(Queue queue) {
    if (queue.rear == queue.header) {
       printf("空队列!\n");
    }
    queueET *cursor = queue.rear;
    while (cursor != queue.header) {
        printf("%d\n", *cursor);
        cursor++;
    }
}