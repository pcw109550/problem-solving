#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // Matrix Chain Multiplication O(N ** 3)
    int N; cin >> N; int E[N + 1] = {};
    for (int i = 0; i < N; i++) {
        cin >> E[i] >> E[i + 1];
    }
    int D[N][N] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            for (int k = j; k < i + j; k++) {
                int temp = D[j][k] + D[k + 1][i + j];
                temp += E[j] * E[k + 1] * E[i + j + 1];
                D[j][i + j] = D[j][i + j] ? min(D[j][i + j], temp) : temp;
            }
        }
    }
    cout << D[0][N - 1] << '\n';
}
