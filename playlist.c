#include<stdio.h>
int main() {
    int n = 0;
    struct info{
        char name[30];
        char singer[30];
    } s[n];

    struct info *sPtr;
    int ip;
    int i = 0;
    int num;
    sPtr = s;

    while (i != 4){
        scanf("%d",&ip);
        if ( ip == 1){
        scanf("%c",sPtr->name);
        scanf("%c",sPtr->singer);
        n += 1;
        sPtr -= n;
        }
        else if(ip == 2){
            scanf("%d",&num);
            //รอใส่ลบ
        }
        else if(ip == 3){
            printf("%d\n",n);
            printf("----------\n");
            for(i=0;i<n;i++){
                printf("%d. %c - %c\n",i+1, sPtr->name, sPtr->singer);
                sPtr++;
            }printf("----------\n");
        }
        else if(ip == 4){
            break;
        }
    }
}