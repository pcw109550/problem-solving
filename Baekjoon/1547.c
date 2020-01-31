#include <stdio.h>
int main(void) {
    int T, a, b; int current[3] = {1, 2, 3}; scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &a, &b);
        if (a == b) { continue; }
        int idx1, idx2, temp;
        for (int i = 0; i < 3; i++) { if (current[i] == a) { idx1 = i; } if (current[i] == b) {idx2 = i; }}
        temp = current[idx1]; current[idx1] = current[idx2]; current[idx2] = temp;
    }
    printf("%d", current[0]);
}