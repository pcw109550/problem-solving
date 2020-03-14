#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, temp; cin >> N >> M;
#ifdef DP // O(n)
    if (M < N) { temp = N; N = M; M = temp; }
    int D[N + 1][M + 1] = {};
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i == 1 && j == 1) { continue; }
            if (j < i) { D[i][j] = D[j][i]; continue; }
            D[i][j] = D[i][j / 2] + D[i][j - j / 2] + 1;
        }
    }
    cout << D[N][M];
#endif // O(1)
    cout << (N - 1) + (M - 1) * N;
}