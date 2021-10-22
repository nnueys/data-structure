#include<stdio.h>

void calArea(float width, float lenght, float *xArea) {
    *xArea = width * lenght;
}
int main()
{
    float w, l, area;
    printf("Enter width : ");
    scanf("%f", &w);
    printf("Enter length : ");
    scanf("%f", &l);
    calArea(w, l, &area);
    printf("rectangle area is %.2f\n", area);
}