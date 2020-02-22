#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M; int input[N + 1][M + 1] = {};
    int D[N + 1][M + 1] = {};
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> input[i][j];
            D[i][j] = D[i - 1][j] + D[i][j - 1] + input[i][j] - D[i - 1][j - 1]; 
        }
    }
    int T, i, j, x, y; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> i >> j >> x >> y;
        cout << D[x][y] - D[i - 1][y] - D[x][j - 1] + D[i - 1][j - 1] << '\n';
    }
}