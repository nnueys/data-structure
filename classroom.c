#include<stdio.h>
#include<math.h>

int main(){
    int num_student, row, reserve;
    int m, i, j, x, y;

    scanf("%d", &num_student);

    if(num_student <= 0){
        printf("Students not enough.");
    }else if(num_student > 40){
        printf("Too many students.");
    }else if(num_student > 0 && num_student <= 40){
        row = ceil(num_student/6);
        char a[row][6];
        for( m = 0 , i = 0; m < num_student ; i++){
            for( j = 0; j < 6 && m < num_student ; m++, j++){
                a[i][j] = 'X';
            }
        }
        scanf("%d", &reserve);

        for(i = 0; i < reserve;i++){
            scanf("%d %d", &x, &y);
            if (y >= 7){
                continue;
            }else{
                a[x-1][y-1] = 'S';
            }
        }
        for( m = 0 , i = 0; m < num_student ; i++){
            for( j = 0; j < 6 && m < num_student ; m++, j++){
                printf("%c " ,a[i][j]);
            }
            printf("\n");
        } 
        }  
}