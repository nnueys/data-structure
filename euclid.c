/*เขียนโปรแกรมภาษา C เขียนฟังก์ชันการหา
gcd ของจำนวนเต็มที่ไม่เป็นค่าลบของจำนวน
2 จำนวน gcd(a,b)  โดยใช้ Euclid's
algorithm*/

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main(){
    printf("%d\n",gcd(10, 100));
    return 0;
}