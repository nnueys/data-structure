#include <stdio.h> 

int tower(int n, char first, char second, char third){
    if (n == 1){
        printf("Move the disk 1 from %c to %c\n", first, second); 
        return 0;
    }
    tower(n-1,first,third,second);
    printf("Move the disk %d from %c to %c\n",n,first,second);
    tower(n-1,third,second,first);
    return 0;
}

int main(){
    char a,b,c;
    int n;

    scanf("%d ",&n);
    scanf("%c %c %c",&a,&b,&c);
    if(n > 0 && n <8){
        tower(n,a,c,b);
    }
    return 0; 
}