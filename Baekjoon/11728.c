#include <stdio.h>
int A[1000001], B[1000001];

int main(void ) {
    int N, M, result; scanf("%d %d", &N, &M);
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }
    while (idx1 < N && idx2 < M) {
        if (A[idx1] > B[idx2]) { printf("%d ", B[idx2++]);}
        else { printf("%d ", A[idx1++]); }
    }
    while (idx1 < N) {
        printf("%d ", A[idx1++]);
    }
    while (idx2 < M) {
        printf("%d ", B[idx2++]);
    }
}