#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char input[10] = {0, };
        scanf("%s", input);
        if (input[1] == '=') { printf("skipped\n"); }
        else {
            int result = 0;
            char* token = strtok(input, "+");
            while (token != NULL) {
                result += atoi(token);
                token = strtok(NULL, "+");
            }
            printf("%d\n", result);
        }
    }
}