
typedef int linkQueueET;

typedef struct Node{
    linkQueueET value;
    struct Node *next;
} Node;

typedef struct {
    Node *rear;
    Node *header;
    int length;
} LinkQueue;

status linkQueueInit(LinkQueue **linkQueue) {
    *linkQueue = malloc(sizeof(LinkQueue));
    if (!*linkQueue) {
        printf("内存分配失败\n");
        return ERROR;
    }
    (*linkQueue)->rear = (*linkQueue)->header = NULL;
    (*linkQueue)->length = 0;
    return SUCCESS;
}

Node* createNode(linkQueueET val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->value = val;
    node->next = next;
    return node;
}

status linkQueuePush(LinkQueue *linkQueue, linkQueueET val) {
    if (linkQueue->header == linkQueue->rear && linkQueue->rear == NULL) {
        Node *node = createNode(val, NULL);
        linkQueue->rear = linkQueue->header = node;
    } else {
        Node *node = createNode(val, linkQueue->rear);
        linkQueue->rear = node;
    }
    linkQueue->length++;
    return SUCCESS;
}


status linkQueuePop(LinkQueue *linkQueue, linkQueueET *res) {

    if (linkQueue->header == linkQueue->rear) {
        if (!linkQueue->rear) {
            printf("空链表队列\n");
            *res = NULL;
            return ERROR;
        }
        *res = linkQueue->header->value;
        linkQueue->rear = linkQueue->header = NULL;
        linkQueue->length--;
        return 0;
    }

    *res = linkQueue->header->value;

    Node *cursor = linkQueue->rear;
    while (cursor->next != linkQueue->header) {
        cursor = cursor->next;
    }
    linkQueue->header = cursor;
    cursor->next = NULL;
    linkQueue->length--;
    return SUCCESS;
}


void linkQueueTraverse(LinkQueue linkQueue) {
    Node *cursor = linkQueue.rear;
    if (linkQueue.header == linkQueue.rear) {
        printf("空队列\n");
        return;
    }
    while (cursor != NULL) {
        printf("%d\n", cursor->value);
        cursor = cursor->next;
    }

}
