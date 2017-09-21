#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 2
#define LISTINCREMENT 1
#define ELASTICITY_SPACE 1

typedef struct {
    int *elem;
    int length;
    int listSize;
} SqList;

typedef int eleType;

void lnitList (SqList *list) {
    list->elem =  malloc(LIST_INIT_SIZE * sizeof(eleType));
    if (!list->elem) {
        exit(0);
    }

    list->length = 0;
    list->listSize = 2;
}

int getListLength(SqList *list) {
    return list->length;
}

int getListSize(SqList *list) {
    return list->listSize;
}
/*
 *  return 返回0是失败, 1成功
    */
int listInsert (SqList *list, int i, int val) {

    //当i>=list->listsize的时候报错
    if (i < 0 || i >= list->listSize) {
        //error code 0
        return 0;
    }

    if (list->length >= list->listSize - ELASTICITY_SPACE) {
        int* newbase = realloc(list->elem, (LISTINCREMENT + list->listSize) * sizeof(eleType));
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

void listShow(SqList *list) {
    for (int i = 0; i < list->length; ++i) {
        int ele = list->elem[i];
        printf("%d\n", ele);
    }

}


int main(int argc) {
    //定义列表
    SqList li;
    //初始化列表
    lnitList(&li);
    // 插入列表数值
    listInsert(&li, 0, 0);
    listInsert(&li, 1, 1);
    listInsert(&li, 2, 2);
    listInsert(&li, 3, 3);
    listInsert(&li, 4, 4);
    listInsert(&li, 2, 20);

    int deleteWord;
    listDelete(&li, 3, &deleteWord);
    printf("删除的是%d\n", deleteWord);
    //展示列表
    listShow(&li);

    printf("总空间是: %d\n", getListSize(&li));
    printf("总长度是: %d\n", getListLength(&li));

    //释放分配的内存
    free(li.elem);
}
//#include <gtk/gtk.h>

//int main (int argc, char *argv[])
//{
//    GtkWidget *window;
//
//    gtk_init(&argc, &argv);
//    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//    /* quit*/ g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(gtk_main_quit),NULL);
//    gtk_window_set_title(GTK_WINDOW(window),"Hello GTK+!");
//    gtk_widget_show(window);
//    gtk_main ();
//
//    return 0;
//}
