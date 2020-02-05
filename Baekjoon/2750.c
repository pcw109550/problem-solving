#include <stdio.h>

int main(void) {
    int N; scanf("%d", &N); int input[1000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
    }
    // Bubble sort
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (input[j] > input[i]) {
                register int temp = input[i]; input[i] = input[j]; input[j] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d\n", input[i]);
    }
}