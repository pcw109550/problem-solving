#include <stdio.h>
int input[64][64];

int count(int x, int y, int k) {
    int result = 0;
    for (int i = x; i < x + k / 2; i++) {
        for (int j = y; j < y + k / 2; j++) {
            result += input[i][j];
        }
    }
    return result;
}

void encode(int k, int x, int y) {
    int total = count(x, y, 2 * k);
    if (total == k * k) { printf("1"); } else if (total == 0) { printf("0"); }
    else {
        printf("(");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int cnt = count(x + i * k / 2, y + j * k / 2, k);
                if (cnt == k / 2 * k / 2) { printf("1"); } else if (cnt == 0) { printf("0"); }
                else { encode(k / 2, x + i * k / 2, y + j * k / 2); }
            }
        }
        printf(")");
    }
}

int main(void) {
    int N; scanf("%d", &N); char temp[65] = {};
    for (int i = 0; i < N; i++) {
        scanf("%s", temp);
        for (int j = 0; j < N; j++) {
            input[i][j] = temp[j] == '1';
        }
    }
    encode(N, 0, 0);
}