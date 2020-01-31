#include <stdio.h>
int main(void) {
    int T; scanf("%d", &T); char input[4];
    for (int i = 0; i < T; i++) {
        scanf("%s", &input); printf("%d\n", input[0] + input[2] - '0' * 2);
    }
}