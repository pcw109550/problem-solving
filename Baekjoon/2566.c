#include <stdio.h>
int main(void) {
    int max = -1, temp, x, y;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &temp);
            if (temp > max) { max = temp; x = i; y = j; }
        }
    }
    printf("%d\n%d %d", max, x + 1, y + 1);
}