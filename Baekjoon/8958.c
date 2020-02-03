#include <stdio.h>
#include <string.h>

int main(void) {
    int T, ans, idx; scanf("%d", &T); char input[81] = {};
    for (int i = 0; i < T; i++) {
        scanf("%s", input); ans = 0; idx = 0;
        for (int j = 0; j < strlen(input); j++) {
            if (input[j] == 'O') { idx++; }
            else { ans += idx * (idx + 1) / 2; idx = 0; }
        }
        ans += idx * (idx + 1) / 2;
        printf("%d\n", ans);
    }
}