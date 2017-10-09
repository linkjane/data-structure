#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "list-u.h"


int main(int argc) {
    Sqlist *sqlist;
    int status = sqlistInit(sqlist);
    printf("%s\n", status == 1 ? "初始化成功" : "初始化失败");
    sqlistAppend(sqlist, 2);
    sqlistAppend(sqlist, 20);
    sqlistAppend(sqlist, 24);

    sqlistInsertBefore(sqlist, 1, 38);

    sqlistDeleteByIndex(sqlist, 1);

    sqlistTraverse(*sqlist);

    printf("长度是: %d\n", sqlist->length);
    printf("最大长度是: %d\n", sqlist->maxSize);
    printf("遍历结束");
}
