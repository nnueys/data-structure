#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char directory[1000000];
char curentNodeName[100];

struct node{
    char name[100];
    struct node* parent;
    struct node* leftChild;
    struct node* rightSibling;
};

struct node* findNodeFromName(char* name, struct node* node)
{
    if (node == NULL){
        return NULL;
    }

    if ( strcmp(node->name, name) == 0){
        return node;
    }
    
    findNodeFromName(name, node->leftChild);

    if ( strcmp(curentNodeName, name) != 0){
        char addSlash[100] = "/";

        strcpy(curentNodeName, name);
        strcat(addSlash, name);
        strcat(directory, addSlash);
    }

    findNodeFromName(name, node->rightSibling);

}

struct node* createRoot(char* name){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->name, name);
    node->parent = NULL;
    node->leftChild = NULL;
    node->rightSibling = NULL;
    return node;
}

struct node* createNode(char* name, struct node* parent){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->name, name);
    node->parent = parent;
    node->leftChild = NULL;
    node->rightSibling = NULL;
    if(node->parent != NULL) {
        if(node->parent->leftChild != NULL) {
            struct node* child = node->parent->leftChild;
            while(child->rightSibling != NULL) {
                child = child->rightSibling;
            }
            child->rightSibling = node;
        }
        else {
        node->parent->leftChild = node;
        }
    }
    return node;

}

int main(){
    int number, j = 0;
    scanf("%d", &number);
    char rootName[100], file1[100], file2[100], findName[100];
    
    scanf("%s", rootName);
    strcpy(directory, rootName);
    struct node* root = createRoot(rootName);
    char listName[100][100];
    strcpy(listName[j], rootName); j++;

    for (int i = 0; i < number; i++){
        scanf("%s %s", file1, file2);
        strcpy(listName[j], file1); j++;
        strcpy(listName[j], file2); j++;
        struct node* Node = createNode(file2, findNodeFromName(file1, root));
    }
    scanf("%s", findName);

    int flag = 1;
    for (int j = 0; listName[j][0] != '\0' ; j++){
        if ( strcmp(listName[j], findName) == 0){
            flag = 0;
            break;
        }
    }
    if (!flag){
        findNodeFromName(findName, root);
        printf("%s\n", directory);
    }

    else printf("No Path!\n");

    
}