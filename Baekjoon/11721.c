#include <stdio.h>
#include <string.h>

int main(void) {
    char input[101] = {}; scanf("%s", input);
    for (int i = 1; i <= strlen(input); i++) {
        printf("%c", input[i - 1]);
        if (i % 10 == 0) { printf("\n"); }
    }
}