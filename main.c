#include <stdio.h>
#include <stdlib.h>

#include "common.h"

#include "linkStack.h"

int main() {
    LinkStack *linkStack;
    linkStackInit(&linkStack);
    linkStackPush(linkStack, 10);
    linkStackPush(linkStack, 20);
    linkStackPush(linkStack, 40);

    linkStackET res;
    linkStackPop(linkStack, &res);
    printf("pop出的值是: %d\n", res);

    linkStackPop(linkStack, &res);
    printf("pop出的值是: %d\n", res);

    linkStackPop(linkStack, &res);
    printf("pop出的值是: %d\n", res);

    linkStackTraverse(linkStack);

    printf("遍历完毕\n");
    printf("当前栈的长度是: %d\n", linkStackLength(*linkStack));


}



