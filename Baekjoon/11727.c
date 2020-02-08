#include <stdio.h>
int D[1001][2];

int main(void) {
    int N; scanf("%d", &N);
    D[1][0] = 0; D[1][1] = 1; D[2][0] = 2; D[2][1] = 1;
    for (int i = 3; i <= N; i++) {
        D[i][0] = (2 * (D[i - 2][0] + D[i - 2][1])) % 10007;
        D[i][1] = (D[i - 1][0] + D[i - 1][1]) % 10007;
    }
    printf("%d", (D[N][0] + D[N][1]) % 10007);
}