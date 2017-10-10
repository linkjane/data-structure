#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "stack.h"

int main() {
    Stack *stack;
    stack->base = malloc(sizeof(int));
    stackInit(stack);
    stack->base[0] = 10;
    stack->top++;
    stackTraverse(stack);
}



