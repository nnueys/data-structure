#include <stdio.h>
#include <math.h>

struct Buy{
    char name[20];
    double price;
};

int main(){
    int total,i;
    double money;
    double min=INFINITY,max=-INFINITY;

    scanf("%d", &total);

    struct Buy thing[total];
    for(i = 0;i < total; i++){
        scanf("%s %lf",thing[i].name,&thing[i].price);
        if(min >= thing[i].price){
            min = thing[i].price;
        }
        if(max <= thing[i].price){
            max = thing[i].price;
        }
    }

    scanf("%lf",&money);

    printf("Max price product(s) is:\n");
    for(i = 0;i < total; i++){
        if(thing[i].price == max){
            printf("    id: %03d name: %s price: %.2lf Baht\n",i+1,thing[i].name,thing[i].price);
        }
    }
    printf("Min price product(s) is:\n");
    for(i = 0 ;i < total;i++){
        if(thing[i].price == min){
            printf("    id: %03d name: %s price: %.2lf Baht\n",i+1,thing[i].name,thing[i].price);
        }
    }
    printf("Products' price that <= %.2lf Baht is:\n",money);
    for(i = 0; i < total ; i++){
        if(thing[i].price <= money){
            printf("    id: %03d name: %s price: %.2lf Baht\n",i+1,thing[i].name,thing[i].price);
        }else if(thing[i].price > money){
            continue;
        }
    }

}