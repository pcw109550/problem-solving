#include <stdio.h>
int main(void) {
    int N, M; scanf("%d %d", &N, &M);
    if (N == 2 && M == 18) { printf("Special"); return 0; }
    if (N > 2) { printf("After"); return 0; }
    if (N == 2 && M > 18) { printf("After"); return 0; }
    printf("Before");
}