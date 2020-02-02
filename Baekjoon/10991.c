#include <stdio.h>

int main(void) {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + i; j++) {
            if ((j - (N + i - 1)) % 2 == 0 && j >= N - 1 - i) { printf("*"); } else { printf(" "); }
        }
        printf("\n");
    }
}