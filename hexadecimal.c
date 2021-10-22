#include <stdio.h>

void change(int n){
    if (n < 10){
        printf("%c", n +'0');
    }else if ( n >= 10 && n <= 15) {
        printf("%c", n + 'A' - 10);
    }else {
        change(n / 16);
        if ((n % 16) < 10 ){
            printf("%c",(n % 16) + '0');
        }else if ( (n % 16) >= 10 && (n % 16) <= 15){
            printf("%c", (n % 16) + 'A' - 10); 
        }      
    }   
}

int main(){
    int n, a, list[20];
    
    scanf("%d", &n);

    for ( int i = 0 ; i < n ; i++) {
        scanf("%d", &list[i]);
    }

    for (int i = 0; i < n ; i++){
        if ( 0 >= list[i] || list[i] > 1000000) {
            printf("%d not in a scope\n", list[i]);
            continue;
        }

        printf("%d = ",list[i]);
        change(list[i]);
        printf("\n");
    }
}