#define INITSIZE 1

typedef int linkStackET;

typedef struct node{
    linkStackET val;
    struct  node *next;
} node;

typedef struct {
    node *base;
    node *top;
    int length;
} LinkStack;

//node *createNode(linkStackET val, node *next) {

//}

void linkStackInit(LinkStack **linkStack) {
    *linkStack = malloc(sizeof(LinkStack));
    if (!*linkStack || !(*linkStack)->base) {
        printf("内存分配失败\n");
        exit(0);
    }
    (*linkStack)->length = 0;
    (*linkStack)->base = NULL;
    (*linkStack)->top = (*linkStack)->base;

}


int linkStackPush(LinkStack *linkStack, linkStackET val) {
    //不存在内存不够用的情况

    node *temp = linkStack->top;

    node* nNode= malloc(sizeof(node));
    nNode->val = val;
    nNode->next = NULL;

    //如果是第一个就直接绑定新节点
    if (linkStack->base == linkStack->top) {
        temp = nNode;
    } else {
        temp->next = nNode;
    }

    linkStack->top = temp->next;
    linkStack->length++;
}

int linkStackLength(LinkStack linkStack) {
    return linkStack.length;
}

void linkStackTraverse(LinkStack *linkStack) {
    if (linkStack->top == linkStack->base) {
        printf("空栈\n");
        return;
    }
    node *cursor = linkStack->base;
    do {
        printf("%d\n", cursor->val);
        cursor = cursor->next;
    } while(cursor != linkStack->top);
}