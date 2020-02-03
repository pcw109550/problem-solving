#include <stdio.h>
#include <string.h>
int main(void) {
    char input[101] = {}; scanf("%s", input); int l = strlen(input);
    for (int i = 0; i < l; i++) {
        if (input[i] != input[l - 1 - i]) { printf("0"); return 0; }
    }
    printf("1");
}