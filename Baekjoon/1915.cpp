#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, result = 0; cin >> N >> M; int input[N][M] = {};
    string s; int D[N + 1][M + 1] = {};
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            input[i][j] = s[j] == '1';
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (input[i - 1][j - 1] == 1) {
                D[i][j] = 1 + min(min(D[i - 1][j], D[i][j - 1]), D[i - 1][j - 1]);
            }
            if (result < D[i][j]) { result = D[i][j]; }
        }
    }
    cout << result * result;
}