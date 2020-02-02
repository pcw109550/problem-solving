#include <stdio.h>
int main(void) {
    int a, b, temp, b1; scanf("%d %d", &a, &b); b1 = b;
    for (int i = 0; i < 3; i++) {
        temp = b % 10; printf("%d\n", a * temp);
        b = (b - temp) / 10;
    }
    printf("%d", a * b1);
}