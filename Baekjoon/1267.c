#include <stdio.h>
int main(void) {
    int N, a = 0, b = 0, temp; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        a += ((temp / 30) + 1) * 10;
        b += ((temp / 60) + 1) * 15;
    }
    if (a < b) { printf("Y %d", a); } 
    if (a > b) { printf("M %d", b); }
    if (a == b) { printf("Y M %d", a); }
}