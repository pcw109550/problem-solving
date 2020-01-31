#include <stdio.h>
int main(void) {
    int len; scanf("%d", &len);
    char input[len + 1]; scanf("%s", &input);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += (input[i] - '0');
    }
    printf("%d", sum);
}