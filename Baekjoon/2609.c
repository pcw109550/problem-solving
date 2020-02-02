#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0) { return a; }
    return gcd(b, a % b);
}

int main(void) {
    int a, b; scanf("%d %d", &a, &b);
    if (a < b) { int temp = b; b = a; a = temp;}
    int result = gcd(a, b);
    printf("%d\n%d", result, a * b / result);
}