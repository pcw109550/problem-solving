#include <stdio.h>
int main(void) {
    int N; scanf("%d", &N);
    int num = 0;
    while (1) {
        scanf("%d", &num); if (num == 0) { return 0; }
        printf("%d is ", num);
        if (num % N != 0) { printf("NOT "); }
        printf("a multiple of %d.\n", N);
    }
}