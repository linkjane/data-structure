#define INITSIZE 1

typedef int linkStackET;
typedef int status;

typedef struct Node{
    linkStackET val;
    struct  Node *next;
} Node;

typedef struct {
    Node *base;
    Node *top;
    int length;
} LinkStack;

//Node *createNode(linkStackET val, Node *next) {

//}

void linkStackInit(LinkStack **linkStack) {
    *linkStack = malloc(sizeof(LinkStack));
    if (!*linkStack) {
        printf("内存分配失败\n");
        exit(0);
    }
    (*linkStack)->length = 0;
    (*linkStack)->base = NULL;
    (*linkStack)->top = (*linkStack)->base;

}

int linkStackIsEmpty(LinkStack linkStack) {
    if (linkStack.top == linkStack.base && !linkStack.base) {
        return 1;
    }
    return 0;
}

status linkStackPop(LinkStack *linkStack, linkStackET *e) {

    if (linkStackIsEmpty(*linkStack)) {
        printf("空栈\n");
        return ERROR;
    }

    Node *oldNode = linkStack->top;
    *e = oldNode->val;
    linkStack->top = oldNode->next;
    //如果top没有值, base也清空
    if (linkStack->top == NULL) {
        linkStack->base = NULL;
    }
    linkStack->length--;

    return SUCCESS;
}

int linkStackPush(LinkStack *linkStack, linkStackET val) {
    //不存在内存不够用的情况

    Node *temp = linkStack->top;

    Node* nNode= malloc(sizeof(Node));
    nNode->val = val;
    nNode->next = NULL;

    //如果是第一个就直接绑定新节点,并赋值给base
    if (linkStack->base == linkStack->top && !linkStack->base) {
        linkStack->base = nNode;
    } else {
        nNode->next = temp;
    }

    linkStack->top = nNode;
    linkStack->length++;

    //释放temp
    temp = NULL;
}



int linkStackLength(LinkStack linkStack) {
    return linkStack.length;
}

void linkStackTraverse(LinkStack *linkStack) {
    if (linkStack->top == linkStack->base && !linkStack->base) {
        printf("空栈\n");
        return;
    }
    Node *cursor = linkStack->top;
    do {
        printf("%d\n", cursor->val);
        cursor = cursor->next;
    } while(cursor != NULL);
}