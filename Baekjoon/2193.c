#include <stdio.h>
unsigned long D[91][2];

int main(void) {
    int N; scanf("%d", &N);
    D[1][0] = 0; D[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        D[i][0] = D[i - 1][0] + D[i - 1][1];
        D[i][1] = D[i - 1][0];
    }
    printf("%lu", D[N][0] + D[N][1]);
}