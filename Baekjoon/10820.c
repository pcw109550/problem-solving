#include <stdio.h>
#include <string.h>

int main(void) {
    char input[101] = {};
    while (scanf("%[^\n]%*c", input) != -1) {
        int lower = 0, upper = 0, num = 0, space = 0;
        for (int i = 0; i < strlen(input); i++) {
            if ('a' <= input[i] && 'z' >= input[i]) { lower++; }
            if ('A' <= input[i] && 'Z' >= input[i]) { upper++; }
            if (' ' == input[i]) { space++; }
            if ('0' <= input[i] && '9' >= input[i]) { num++; }
        }
        printf("%d %d %d %d\n", lower, upper, num, space);
    }
}