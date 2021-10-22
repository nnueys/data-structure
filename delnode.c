#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *next;
} Node;

typedef struct linked_list {
    int length;
    Node *head;
} NumList;

Node *newNode(){
    Node *a;
    a = (Node *) malloc(sizeof(Node));
    a->next = NULL;
    return a;
}

void initList(NumList *n) {
    n->head = NULL;
}

int appendHeadList(NumList *l, Node *a) {
    if (l->head == NULL) {
        l->head = a;
    } else {
        a->next = l->head;
        l->head = a;
    }
}

void deleteEnd(NumList L){
    Node *aCurr = L.head;
    Node *arev;

    while (aCurr != NULL) {
        arev = aCurr;
        aCurr = aCurr->next;
        if (aCurr->next == NULL) {
            arev->next = NULL;
            free(aCurr);
            break;
        }
    }
}

void printNumList(NumList L) {
    Node *aCurr = L.head;
    printf("List : ");
    while (aCurr != NULL){
        printf("%d ", aCurr->num);
        aCurr = aCurr->next;
    }
    printf("\n");
}

int main() {
    NumList NL;
    Node *N;
    initList(&NL);
    for (int i = 0; i<3; i++) {
        N = newNode();
        N->num = i;
        appendHeadList(&NL,N);
    }
    printNumList(NL);
    deleteEnd(NL);
    printf("After delete last node\n");
    printNumList(NL);
}