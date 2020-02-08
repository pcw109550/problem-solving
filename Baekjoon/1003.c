#include <stdio.h>
int D[42]; 

int main(void) {
    D[0] = 1;
    for (int i = 2; i < 42; i++) {
        D[i] = D[i - 1] + D[i - 2];
    }
    int T, a; scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &a); printf("%d %d\n", D[a], D[a + 1]);
    }
}