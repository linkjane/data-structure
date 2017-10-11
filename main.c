#include <stdio.h>
#include <stdlib.h>

#include "common.h"

#include "linkStack.h"

int main() {
    LinkStack *linkStack;
    linkStackInit(linkStack);
    linkStackPush(linkStack, 10);

    linkStackTraverse(linkStack);

    printf("遍历完毕\n");
    printf("当前栈的长度是: %d\n", linkStackLength(*linkStack));


}



