#include <stdio.h>
int input[100001];
int D[100001];
int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &input[i]);
    }
    D[1] = input[1]; int result = D[1];
    for (int k = 2; k <= N; k++) {
        D[k] = max(0, D[k - 1]) + input[k];
        if (result < D[k]) { result = D[k]; }
    }
    printf("%d", result);
}