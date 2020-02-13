#include <stdio.h>

int main(void) {
    int input, result = 0;
    while(scanf("%d", &input) != -1) {
        if (input > 0) { result++; }
    }
    printf("%d", result);
}