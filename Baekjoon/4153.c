#include <stdio.h>

int max(int a, int b) { return a < b ? b : a; }
int min(int a, int b) { return a > b ? b : a; }

int main(void) {
    int a, b, c, M, m, t;
    while (1) {
        scanf("%d %d %d", &a, &b, &c); if (a == 0 && b == 0 && c == 0) { return 0; }
        M = max(max(a, b), c); m = min(min(a, b), c); t = a + b + c - M - m;
        if (m * m + t * t == M * M) { printf("right\n"); } else { printf("wrong\n"); }
    }
}