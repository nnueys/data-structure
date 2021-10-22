#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *leftLink;
    struct node * rightLink;
} Node;


Node *newNode(int data){
    Node *temp;
    temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    temp->rightLink = NULL;
    temp->leftLink = NULL;
    return temp; 
}
int main(){
    Node *first, *second;
    Node *head;
    first = newNode(6);
    second = newNode(23);

    head = first;

    first->rightLink = second;

    second->leftLink = first;

    printf("first leftLink :%s \n",first->leftLink);
    printf("first rightLink :%d \n",first->rightLink->data);

    printf("second leftLink :%d \n",second->leftLink->data);
    printf("second rightLink :%s \n",second->rightLink);

}