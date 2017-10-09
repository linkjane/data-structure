#include <stdio.h>



//列表定义
typedef struct LNode{
    int data;
    struct LNode* next;
} LNode;

//定义声明
typedef void (*callback)(LNode* data);
void traverse(LNode* head, callback f);
int count(LNode* head);
LNode* insertAfter(LNode* head, int data, LNode* prev);
LNode* prepend(LNode* head, int data);
LNode* append (LNode* head, int data);
LNode* search(LNode* head, int data);
LNode* insertBefore(LNode* head, int data, LNode* nex);


void traverse(LNode* head, callback f) {
    LNode* cursor = head;
    while (cursor != NULL) {
        f(cursor);
        cursor = cursor->next;
    }
}

int count(LNode* head) {
    LNode* cursor = head;
    int c = 0;
    while (cursor != NULL) {
        c++;
        cursor = cursor->next;
    }
    return c;
}
//初始化列表
LNode* llCreate(int data, LNode* next) {
    LNode* newNode = malloc(sizeof(LNode));
    if (newNode == NULL) {
        printf("error create a node");
        exit(0);
    }
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

LNode* insertAfter(LNode* head, int data, LNode* prev) {
    LNode* cursor = head;
    while (cursor != prev) {
        cursor = cursor->next;
    }
    if (cursor != NULL) {
        LNode* newNode = llCreate(data, cursor->next);
        cursor->next = newNode;
        return head;
    } else {
        return NULL;
    }
}

LNode* insertBefore(LNode* head, int data, LNode* nex) {

    if (nex == NULL || head == NULL) {
        return NULL;
    }

    if (nex == head) {
        head = prepend(head,data);
        return head;
    }

    LNode* cursor = head;
    while(cursor->next != nex) {
        cursor = cursor->next;
    }
    if (cursor != NULL) {
        LNode* newNode = llCreate(data, cursor->next);
        cursor->next = newNode;
        return newNode;
    } else {
        return NULL;
    }

}

LNode* search(LNode* head, int data) {
    LNode* cursor = head;
    while (cursor->data != data) {
       cursor = cursor->next;
    }
    if (cursor == NULL) {
        return NULL;
    }
    return cursor;
}

LNode* append (LNode* head, int data) {
    LNode* cursor = head;
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    LNode* newNode = llCreate(data, NULL);
    cursor->next = newNode;
    return head;
}

LNode* prepend(LNode* head, int data) {
    LNode* newNode = llCreate(data, head);
    head = newNode;
    return head;
}


//插入排序

LNode* reverse(LNode* head) {
    LNode* current = head;
    LNode* prev = NULL;
    LNode* temp = NULL;
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    /*
    while (current != NULL) {
        //先存本节点的拷贝
        temp = current;
        //指针下移动
        current = current->next;
        temp->next = prev;
        prev = temp;
    }*/
    return prev;
}

LNode* removeFront(LNode* head) {
    if (head == NULL) {
        return NULL;
    }
    LNode* front = head;
    head = head->next;
    front->next = NULL;
    //todo 这句话没有理解是干什么的
    //如果只有一个node
    if (head == front) {
       head = NULL;
    }
    free(front);
    return head;
}

LNode* removeBack(LNode* head) {

    if (head->next == NULL) {
        head = NULL;
        return head;
    }

    LNode* cursor = head;
    LNode* backOneNode = NULL;
    while(cursor->next != NULL) {
        backOneNode = cursor;
        cursor = cursor->next;
    }
    //back有可能是NULL
    if (backOneNode != NULL) {
        backOneNode->next = NULL;
    }

    if (cursor == head) {
        head = NULL;
    }
    //释放cursor
    free(cursor);

    return head;
}

LNode* removeAny(LNode* head, LNode* rmNode) {
    if (head == rmNode) {
        head = removeFront(rmNode);
        return head;
    } else if (rmNode->next == NULL) {
        head = removeBack(rmNode);
        return head;
    }

    LNode* cursor = head;
    LNode* cur = NULL;
    while (cursor->data != rmNode->data) {

    }
    while (cursor->next->data != rmNode->data) {
        cur = cursor->next->next;
        cursor = cursor->next;
    }


    cursor->next = cur;

    return head;

}