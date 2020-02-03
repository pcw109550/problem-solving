#include <stdio.h>
#include <string.h>
int main(void) {
    char input[21] = {}; scanf("%s", input); int N = strlen(input);
    for (int i = 0; i < N; i++) {
        if (input[i] != input[N - i - 1]) { printf("false"); return 0; }
    }
    printf("true");
}