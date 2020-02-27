#include <bits/stdc++.h>
using namespace std;
int N, M, K;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int result; cin >> N >> M >> K;
    int D[N][M] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 || j == 0) { D[i][j] = 1; continue; }
            else {
                D[i][j] = D[i - 1][j] + D[i][j - 1];
            }
        }
    }
    if (K == 0) { result = D[N - 1][M - 1]; }
    else { K--;
        int x = K % M, y = K / M;
        result = D[y][x] * D[N - y - 1][M - x - 1];
    }
    cout << result;
}