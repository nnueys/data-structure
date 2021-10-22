#include <stdio.h>

int an(int i)
{
    if(i==1){
        return 2;
    }else{
        return an(i-1)+3;
    }
}

int main()
{
    printf("ans = %d\n",an(5));
}

//แผนภาพ
// an(5)
// = 3 + an(4)
// = 3 + 3 + an(3)
// = 3 + 3 + 3 + an(2)
// = 3 + 3 + 3 + 3 + an(1)
// = 3 + 3 + 3 + 3 + 2
