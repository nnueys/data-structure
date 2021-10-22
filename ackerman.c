#include<stdio.h>

int acker(int m,int n){
    
    if(m==0){
        return n+1;
    }
    else if((m>0) && (n==0)){
        return acker(m-1,1);
    }
    else if((m>0) && (n>0)){
        return acker(m-1,acker(m,n-1));
    }
}

int main(){
    printf("%d",acker(1,2));
}

/*แผนภาพ
A(1,2) -> m=1 > 0 , n=2 > 0
A(1,2) = A(0,A(1,1))
    A(1,1) = A(0,A(1,0))
        A(1,0) = A(0,1) 
        -> 1 + 1 = 2
    A(1,1) = A(0,2) 
    -> 2 + 1 = 3
A(1,2) = A(0,3) 
-> 3 + 1 = 4 */
