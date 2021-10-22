#include <stdio.h>

int a(int n, int sum) {
    if (n == 1) {
        printf("%d ", sum);
        return sum;
    } else {
        printf("%d ",sum);
        return a(n-1,sum+3);
    }
}

int main() {
    a(5, 2);
}


/*แผนภาพ
a(1) = 2
a(2) = a(2-1) + 3 -> a(1) + 3 -> 2 + 3 = 5
a(3) = a(3-1) + 3 -> a(2) + 3 -> 5 + 3 = 8
a(4) = a(4-1) + 3 -> a(3) + 3 -> 8 + 3 = 11
a(5) = a(5-1) + 3 -> a(4) + 3 -> 11 + 3 = 14
*/