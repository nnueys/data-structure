/*•ให้เขียนคำสั่งของการย้ายจานและวาดภาพประกอบ
กรณีที่ N=3
ให้บอกจำนวนครั้งของการย้ายว่ารวมแล้วมีการย้ายกี่ครั้ง(ไม่นับการเรียกครั้งแรก เช่น n=2 จะมีจำนวนครั้งการเรียกเป็น 3)*/

#include <stdio.h>
int sum = 0;
void hanoi(int n, char x, char y, char z){
    if (n == 1) {
        printf("Move disk %d from %c to %c\n",n , x, z);
        sum += 1;
        return;
    }
    //move out
    hanoi(n-1,x,z,y);
    printf("Move disk %d from %c to %c\n",n , x, z);
    sum += 1;

    //move in
    hanoi(n-1,y,x,z);

}

int main(){
    hanoi(3,'A','B','C');
    printf("= This disk use %d steps.\n",sum );
    // return 0;
}