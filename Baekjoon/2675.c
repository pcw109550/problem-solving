#include <stdio.h>
int main(void) {
    int T; scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int num; char input[21] = {};
        scanf("%d %s", &num, &input);
        for (int j = 0; j < 21; j++) {
            if (input[j] == 0) { break;}
            for (int k = 0; k < num; k++) {
                printf("%c", input[j]);
            }
        }
        printf("\n");
    }
}