#include <stdio.h>
#define NUM 1000000000
int D[101][10];

int main(void) {
    int N; scanf("%d", &N);
    for (int i = 1; i < 10; i++) { D[1][i] = 1; }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j - 1 >= 0) { D[i][j] = (D[i][j] + D[i - 1][j - 1]) % NUM; }
            if (j + 1 <= 9) { D[i][j] = (D[i][j] + D[i - 1][j + 1]) % NUM; }
        }
    }
    int result = 0;
    for (int i = 0; i < 10; i++) { result = (result +  D[N][i]) % NUM; }
    printf("%d", result);
}