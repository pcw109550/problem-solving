#include <stdio.h>
int main(void) {
    char map[5] = {'D', 'C', 'B', 'A', 'E'};
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        int input[4] = {}; scanf("%d %d %d %d", &input[0], &input[1], &input[2], &input[3]);
        printf("%c\n", map[input[0] + input[1] + input[2] + input[3]]);
    }
}