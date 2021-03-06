#include <bits/stdc++.h>
using namespace std;

inline void task() {
    // Matrix Chain Multiplication O(N ** 3)
    int N; cin >> N;
    int input[N] = {};
    int acc[N + 1] = {};
    for (int i = 0; i < N; i++) {
        cin >> input[i];
        acc[i + 1] = acc[i] + input[i];
    }
    int D[N][N] = {}; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            for (int k = j; k < i + j; k++) {
                int temp = D[j][k] + D[k + 1][i + j] + acc[i + j + 1] - acc[j];
                D[j][i + j] = D[j][i + j] ? min(D[j][i + j], temp) : temp;
            }
        }
    }
    cout << D[0][N - 1] << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while (T--) { task(); }
}
