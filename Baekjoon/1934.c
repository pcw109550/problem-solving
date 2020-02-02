#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0) { return a; }
    return gcd(b, a % b);
}

int main(void) {
    int T, result, a, b; scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &a, &b);
        if (a < b) { int temp = b; b = a; a = temp;}
        result = gcd(a, b);
        printf("%d\n", a * b / result);
    }
}