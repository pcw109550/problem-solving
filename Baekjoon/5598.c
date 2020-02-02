#include <stdio.h>
#include <string.h>
int main(void) {
    char input[1001] = {}; scanf("%s", input);
    for (int i = 0; i < strlen(input); i++) {
        input[i] = (26 + input[i] - 'A' - 3) % 26 + 'A';
    }
    printf("%s", input);
}