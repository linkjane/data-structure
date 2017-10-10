#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "stack.h"

int main() {
    Stack *stack;
    stack = malloc(sizeof(Stack));
    stackInit(stack);

    stackPush(stack, 20);
    stackPush(stack, 25);
    stackPush(stack, 37);


    stackTraverse(stack);

    int val = stackPop(stack);
    printf("弹出顶元素是: %d\n", val);

    val = stackPop(stack);
    printf("弹出顶元素是: %d\n", val);

    val = stackPop(stack);
    printf("弹出顶元素是: %d\n", val);

    stackTraverse(stack);

    printf("遍历完毕\n");
    printf("最大空间是: %d\n", stack->maxSize);
    printf("当前长度是: %d\n", stackGetLength(*stack));
}



