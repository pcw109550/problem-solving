#include <stdio.h>
int main(void) {
    int min = 1000001, max = -min;
    int N, temp; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        if (temp > max) { max = temp; }
        if (temp < min) { min = temp; }
    }
    printf("%d %d", min, max);
}