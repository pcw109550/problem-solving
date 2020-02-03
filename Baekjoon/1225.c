#include <stdio.h>
#include <string.h>

int main(void) {
    char a[10001] = {}, b[10001] = {}; scanf("%s %s", a, b);
    int al = strlen(a), bl = strlen(b);
    long long sum = 0;
    for (int i = 0; i < al; i++) {
        for (int j = 0; j < bl; j++) {
            sum += (a[i] - '0') * (b[j] - '0');
        }
    }
    printf("%lld", sum);
}