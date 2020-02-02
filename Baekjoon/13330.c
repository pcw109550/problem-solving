#include <stdio.h>

int main(void) {
    int N, K, S, Y; scanf("%d %d", &N, &K);
    int result = 0; int store[6][2] = {};
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &S, &Y);
        store[Y - 1][S] += 1;
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            if (store[i][j] != 0) { result += (store[i][j] / K) + (store[i][j] % K != 0);  }
        }
    }
    printf("%d", result);
}