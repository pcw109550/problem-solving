#include <bits/stdc++.h>
using namespace std;
int N;
char input[2187][2187];
int A[3];

void count(int n, int x, int y) {
    int a[3] = {}; bool paper = false;
    for (int i = x - n / 2; i <= x + n / 2; i++) {
        for (int j = y - n / 2; j <= y + n / 2; j++) {
            a[(int)input[i][j] + 1]++;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (a[i] == n * n) { A[i]++; paper = true; }
    }
    if (!paper && n > 1) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                count(n / 3, x + i * n / 3, y + j * n / 3);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N; int temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp;
            input[i][j] = temp;
        }
    }
    count(N, N / 2, N / 2);
    cout << A[0] << '\n' << A[1] << '\n' << A[2];
}