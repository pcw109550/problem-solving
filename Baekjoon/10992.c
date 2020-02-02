#include <stdio.h>

int main(void) {
    int N; scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N + i; j++) {
            if (j == N + i - 1 || j == N - i - 1) { printf("*"); } else { printf(" "); }
        }
        printf("\n");
    }
    for (int j = 0; j < 2 * N - 1; j++) { printf("*"); }   
}