#include <stdio.h>
#include <string.h>

int main(void) {
    char input[101] = {};
    scanf("%s", input);
    printf("%c", input[0]);
    for (int i = 1; i < strlen(input); i++) {
        if (input[i] == '-') { printf("%c", input[i + 1]); }
    }
}