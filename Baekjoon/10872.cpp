#include <stdio.h>
int factorial(int n) {
    if (n <= 1) { return 1; }
    else { return n * factorial(n - 1); }
}

int main(void) {
    int N; scanf("%d", &N);
    printf("%d\n", factorial(N));
}