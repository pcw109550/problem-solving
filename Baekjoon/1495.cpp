#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, S, M; cin >> N >> S >> M; int V[N + 1] = {};
    for (int i = 1; i <= N; i++) { cin >> V[i]; }
    bool D[N + 1][M + 1] = {}; D[0][S] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (D[i - 1][j]) {
                if (j + V[i] <= M) { D[i][j + V[i]] = true; }
                if (j - V[i] >= 0) { D[i][j - V[i]] = true; }
            }
        }
    }
    int Max = -1;
    for (int j = 0; j <= M; j++) {
        if (D[N][j]) { Max = max(Max, j); }
    }
    cout << Max;
}