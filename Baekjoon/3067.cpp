#include <bits/stdc++.h>
using namespace std;

inline void eval() {
    int N, K;
    cin >> N; int A[N] = {};
    for (int i = 0; i < N; i++) { cin >> A[i]; }
    cin >> K;
    int D[N][K + 1] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            if (i == 0) {
                D[i][j] = j % A[0] == 0;
            } else {
                D[i][j] = D[i - 1][j] + (j < A[i] ? 0 : D[i][j - A[i]]);
            }
        }
    }
    cout << D[N - 1][K] << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        eval();
    }
}