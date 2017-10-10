
#define INITSIZE 1;


typedef int stackET;

typedef struct{
    int *base;
    int *top;
} Stack;

int stackInit(Stack *stack) {
    //初始化只有1个可以存储的空间
    stack->base = malloc(sizeof(int));
    if (!stack->base) {
        printf("分配失败");
        return ERROR;
    }
    stack->top = stack->base;
}

int stackTraverse(Stack *stack) {

    if (stack->top == stack->base) {
        printf("no data\n");
        return ERROR;
    }

    int *copyBase = stack->base;
    while(copyBase != stack->top) {
        printf("%d\n", *copyBase);
        copyBase++;
    }
    return SUCCESS;
}