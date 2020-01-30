#include <stdio.h>
int main(void) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    int result = 0;
    if (a == b && b == c) {
        result = 10000 + a * 1000;
    } else if (a == b) {
        result = 1000 + a * 100;
    } else if (b == c) {
        result = 1000 + b * 100;
    } else if (a == c) {
        result = 1000 + c * 100;
    } else {
        int temp = a > b ? a : b;
        result = 100 * (temp > c ? temp : c); 
    }
    printf("%d\n", result);
}