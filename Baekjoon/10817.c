#include <stdio.h>
int max(int a, int b) { return a < b ? b : a; }
int min(int a, int b) { return a < b ? a : b; }

int main(void) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", a + b + c - min(min(a, b), c) - max(max(a, b), c));
}