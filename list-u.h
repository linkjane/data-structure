
#define INITSIZE 10

typedef int listET;

typedef struct {
    int *list;
    int length;
    int maxSize;
} Sqlist;

int sqlistInit(Sqlist *sqlist) {
    sqlist->list = malloc(sizeof(listET) * INITSIZE);
    if (!sqlist->list) {
        printf("分配失败\n");
        return ERROR;
    }
    sqlist->length = 0;
    sqlist->maxSize = 1;
    return SUCCESS;
}

int sqlistAppend(Sqlist *sqlist, listET val) {

    if (sqlist->length >= sqlist->maxSize) {
        sqlist->maxSize *= 2;
        sqlist->list = realloc(sqlist->list, sizeof(listET) * sqlist->maxSize);
        if (!sqlist->list) {
            printf("分配失败\n");
            return ERROR;
        }
    }
    sqlist->list[sqlist->length++] = val;
    return SUCCESS;
}

int sqlistInsertBefore(Sqlist *sqlist, int index, listET val) {
    if (index < 0 || index > sqlist->length - 1) {
        printf("输入下标错误\n");
       return ERROR;
    }

    if (sqlist->length == 0) {
        int status = sqlistAppend(sqlist, val);
        if (status == ERROR) {
            printf("分配失败\n");
            return ERROR;
        }
        return SUCCESS;
    }

    if (sqlist->length >= sqlist->maxSize) {
        sqlist->maxSize *= 2;
        sqlist->list = realloc(sqlist->list, sizeof(listET) * sqlist->maxSize);
        if (!sqlist->list) {
            printf("分配失败\n");
            return ERROR;
        }
    }
    for (int i = sqlist->length ; i > index ; --i) {
       sqlist->list[i] = sqlist->list[i - 1];
    }
    sqlist->list[index] = val;
    sqlist->length++;
}

//删除用不用释放内存
int sqlistDeleteByIndex(Sqlist *sqlist, int index) {
    if (index < 0 || index > sqlist->length - 1) {
        return ERROR;
    }
    if (sqlist->length == 0) {
        printf("no data\n");
        return ERROR;
    }
    for (int i = index; i < sqlist->length - 1; ++i) {
        printf("值是%d\n", sqlist->list[i + 1]);
        sqlist->list[i] = sqlist->list[i + 1];
    }
    sqlist->length--;

}

void sqlistTraverse(Sqlist sqlist) {
    for (int i = 0; i < sqlist.length; ++i) {
        printf("%d \n", sqlist.list[i]);
    }
}





