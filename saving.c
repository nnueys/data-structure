#include<stdio.h>

int main(){
    double money, interest;
    int year;

    scanf("%lf", &money);
    scanf("%lf", &interest);
    scanf("%d", &year);
    
    if (year >= 0 && money >= 0 && interest >= 0){
        for(int i = 0 ; i < year ; i++){
            money = ( money * ( interest / 100 )) + money;
        }
        printf("%.2lf\n",money);                           
    }
    return 0;
} 