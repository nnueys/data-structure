#include <stdio.h>

int main() {
    int n , a;
    int index = 0;
    int list[20];

    scanf("%d",&n);

    for (int i = 0 ; i < n ; i++){
        scanf("%d", &list[i]);
    }

    if ( n == 1 ){
        printf("%d",list[0]);
        return 0;
    }else if ( n == 0 ){
        printf("0");
        return 0;
    }

    a = n;
    for( int i = 0 ; i < n-1 ; i++) {
        for ( int j = 0 ; j < a-1 ; j++){
            list[index+a] = list[index] + list[index+1];
            index++;
        }
        index++;
        a--;
    }

    for (int i = 0; i < n ; i++) {
        for ( int j = 0 ; j < a ; j++) {
            printf("%d%s ", list[(index+j)], (j==i)?" ":",");
        }
        a++;
        index -= a;
        printf("\n");
    }
}
