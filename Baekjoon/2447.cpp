#include <bits/stdc++.h>
using namespace std;
int n = 0;

void func(int N, int a, int b, char *output) {
    if (N == 1) { return; }
    for (int i = a - N / 6; i <= a + N / 6; i++) {
        for (int j = b - N / 6; j <= b + N / 6; j++) {
            *(output + n * i + j) = ' ';
        }
    }
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            func(N / 3, a + i * N / 3, b + j * N / 3, output);
        }
    }
    
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; char output[N][N] = {}; memset(&output, '*', N * N);
    n = N;
    func(N, (N - 1) / 2, (N - 1) / 2, (char *)&output);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << output[i][j];
        }
        cout << '\n';
    }
}