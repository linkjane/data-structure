
#define INITSIZE 1;


typedef int stackET;

typedef struct{
    int *base;
    int *top;
    int maxSize;
} Stack;

int stackInit(Stack *stack) {
    //初始化只有1个可以存储的空间
    stack->base = malloc(sizeof(int));
    if (!stack->base) {
        printf("分配失败");
        return ERROR;
    }
    stack->top = stack->base;
    stack->maxSize = 1;
}

int stackPush(Stack *stack, stackET val) {
    int length = stack->top - stack->base;
    if (length >= stack->maxSize) {
        stack->maxSize *= 2;
        stack->base = realloc(stack->base, sizeof(stackET) * stack->maxSize);
    }
    *(stack->top++) =  val;
    stack->maxSize++;
}

int stackGetLength(Stack stack) {
    return stack.top - stack.base;
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