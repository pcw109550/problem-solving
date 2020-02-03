#include <stdio.h>
int N;
int input[20][20];
int isused[20];
int arr[10], arr2[10];
int result = 2147483647;

int abs(int a) {
    return a > 0 ? a : -a;
}

void backtrack(int k) {
    if (k == N / 2) {        
        int team1 = 0, team2 = 0;
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < N / 2; j++) {
                team1 += input[arr[i]][arr[j]];
            }
        }
        int idx = 0, idx2 = 0;      
        for (int i = 0; i < N; i++) {
            if (arr[idx2] == i) { idx2++; }
            else { arr2[idx++] = i; }
        }
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < N / 2; j++) {
                team2 += input[arr2[i]][arr2[j]];
            }
        }
        if (result > abs(team1 - team2)) { result = abs(team1 - team2); }
        return;
    }
    for (int i = 0; i < N; i++) { 
        if (!isused[i]) {
            if (k == 0 || arr[k - 1] < i) {
                isused[i] = 1; arr[k] = i; backtrack(k + 1); isused[i] = 0;
            }
        }
    }
}

int main(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &input[i][j]);
        }
    }
    backtrack(0);
    printf("%d", result);
}