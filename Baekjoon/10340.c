#include <stdio.h>
int main(void) {
    int A, B, C; scanf("%d %d %d", &A, &B, &C);
    int res1, res2, res3, res4;
    res1 = res2 = (A + B) % C;
    res3 = res4 = (A * B) % C;
    printf("%d\n%d\n%d\n%d", res1, res2, res3, res4);
}