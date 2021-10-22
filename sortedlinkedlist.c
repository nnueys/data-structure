#include <stdio.h>
#include <stdlib.h>

typedef struct numberArr{
    int num;
    struct numberArr *nextNode;
}aon;

aon *head = NULL, *tail =  NULL;

void sortList() {
    aon *curr = head, *index = NULL;
    int tmp;
    while (curr != NULL) {
        index = curr->nextNode;
        while (index != NULL) {
            if (curr->num > index->num) {
                tmp = curr->num;
                curr->num = index->num;
                index->num = tmp; 
            }
            index = index->nextNode;
        }
        curr = curr->nextNode;
    }
}

void printList() {
    aon *index = head;
    while (index != NULL) {
        printf("%d ", index->num);
        index = index->nextNode;
    }
    printf("\n");
}

void addNum(int num) {
    aon *node = (aon *)malloc(sizeof(aon));
    node->num = num;
    node->nextNode = NULL;
    
    if (head == NULL) {
        head = node;
        tail = node;
    } else {
        tail->nextNode = node;
        tail = node;
    }
    sortList();
    printList();
}

void delNum(int num) {
    aon *index = head, *prev = NULL;
    sortList();
    if (index != NULL && index->num == num) {
        head = index->nextNode;
        free(index);
        printList();
    } else {
        while (index != NULL && index->num != num) {
            prev = index;
            index = index->nextNode;
        }
        if (index == NULL) {
            printList();
            return;
        }
        else if (index->nextNode == NULL) {
            prev->nextNode = NULL;
            tail = prev;
            printList();
            return;
        }
        prev->nextNode = index->nextNode;
        free(index);
        printList();
    }
}

int main() {
    char type;
    int ipnum;
    while (1) {
        scanf("%c", &type);
        if (type == 'A') {
            scanf("%d", &ipnum);
            addNum(ipnum);
        } else if (type == 'D') {
            scanf("%d", &ipnum);
            delNum(ipnum);
        } else if (type == 'Q') {
            printList();
            break;
        }
    }
}