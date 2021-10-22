#include<stdio.h>
#include<string.h>
int main() {
    struct info {
        char name[20];
        int age;
    } s[5];

    int i;
    struct info *sPtr;
    sPtr = s;

    for(i = 0; i < 5; i++){
        printf("Enter name and age student No.%d : ",i+1);
        scanf("%s %d",sPtr->name, &(sPtr->age));
        sPtr++;
    }
    sPtr -= 5;

    printf("Student's age over 20 is :\n");   
    for(i = 0; i < 5; i++) {
        if ((sPtr->age) > 20)
            printf("-> %s\n",sPtr->name);
        sPtr++;
    }
    return 0;
}
