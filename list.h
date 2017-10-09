#define LIST_INIT_SIZE 2
#define LISTINCREMENT 1
#define ELASTICITY_SPACE 1

typedef struct {
    int *elem;
    int length;
    int listSize;
} SqList;

typedef int eleType;

void lnitList(SqList *list) {
    list->elem = malloc(LIST_INIT_SIZE * sizeof(eleType));
    if (!list->elem) {
        exit(0);
    }

    list->length = 0;
    list->listSize = 2;
}

int listLength(SqList *list) {
    return list->length;
}

int getListSize(SqList *list) {
    return list->listSize;
}

/*
 *  return 返回0是失败, 1成功
    */
int listInsert(SqList *list, int i, int val) {

    //当i>=list->listsize的时候报错
    if (i < 0 || i >= list->listSize) {
        //error code 0
        return 0;
    }

    if (list->length >= list->listSize - ELASTICITY_SPACE) {
        int *newbase = realloc(list->elem, (LISTINCREMENT + list->listSize) * sizeof(eleType));
        if (!newbase) {
            printf("%s", "overflow");
        }
        list->elem = newbase;
        list->listSize += LISTINCREMENT;
    }


    for (int j = list->length - 1; j >= i; j--) {
        list->elem[j + 1] = list->elem[j];
    }

    list->elem[i] = val;
    list->length++;

    return 1;
}

/*
 *  return 返回0是失败, 1成功
 *  e 删除的值返回
 */
int listDelete(SqList *list, int i, int *e) {

    if (i < 0 || i >= list->length || list->length == 0) {
        return 0;
    }
    *e = list->elem[i];
    for (int j = i; j <= list->length - 2; ++j) {
        list->elem[j] = list->elem[j + 1];
    }
    list->length--;
    return 1;
}

void destroyList(SqList *list) {
    list = NULL;
}

int listIsEmpty(SqList *list) {
    if (list->length == 0) {
        return 1;
    }

    return 0;
}

int getEle(SqList *list, int i, eleType *e) {
    if (i >= list->length) {
        return 0;
    }
    int val = list->elem[i];
    if (val) {
        *e = val;
        return 1;
    }
    return 0;
}

int locateElem(SqList *list, int val, int *location) {
    for (int i = 0; i < list->length; ++i) {
        if (list->elem[i] == val) {
            *location = i;
            return 1;
        }
    }
    return 0;
}

void priorElem(SqList *list, eleType curElem, eleType *preElem) {
    for (int i = 0; i < list->length; ++i) {
        if (list->elem[i] == curElem) {
            if (i == 0) {
                printf("没有前驱\n");
                break;
            }
            *preElem = list->elem[i - 1];
            break;
        }
    }
}

void nextElem(SqList *list, eleType curElem, eleType *nextElem) {
    for (int i = 0; i < list->length; ++i) {
        if (list->elem[i] == curElem) {
            if (i == (list->length - 1)) {
                printf("没有后继\n");
                break;
            }

            *nextElem = list->elem[i + 1];
            break;
        }
    }
}

void listTraverse(SqList *list/*, visit() 什么意思?作用是什么呢?*/) {
    eleType *j = list->elem;
    eleType *i = list->elem + list->length - 1;
    int tem = 0;
    while (j < i) {
        tem = *j;
        *j = *i;
        *i = tem;
        i--;
        j++;
    }
}

void listShow(SqList *list) {
    if (list->length == 0) {
        printf("空列表\n");
        return;
    }

    for (int i = 0; i < list->length; ++i) {
        int ele = list->elem[i];
        printf("%d\n", ele);
    }
}